import copy
import random
from typing import NamedTuple
from hyperopt import fmin, tpe, hp, Trials
from src.results import plotResults
from src.taxi import run
from src.args import QParameters


class Metrics(NamedTuple):
    args: QParameters
    score: float
    avg_reward: float
    median_reward: float
    max_reward: float
    min_reward: float


class Optimizer:
    def __init__(self, base_params: QParameters):
        self.base_params = base_params

    def optimize(self) -> QParameters:
        if self.base_params.optimize_with_bayesian:
            return self.optimize_bayesian()
        elif self.base_params.optimize_with_variations:
            return self.optimize_variations()
        else:
            raise ValueError("Aucune méthode d'optimisation activée.")

    def optimize_variations(self) -> QParameters:
        best_params = copy.deepcopy(self.base_params)
        best_score = float("-inf")

        print("\n🚀 Optimisation avec variations aléatoires...")

        for i in range(self.base_params.variations_number):
            print(f"\n🔄 Variation {i + 1}/{self.base_params.variations_number}")
            new_params = self._generate_variation()
            score = self._evaluate_model(new_params)

            if score > best_score:
                best_score = score
                best_params = new_params
                print("✅ Nouveau meilleur modèle trouvé !")

        print("\n🏆 Meilleurs hyperparamètres trouvés :")
        self._print_params(best_params)
        return best_params

    def optimize_bayesian(self) -> QParameters:
        def objective(params):
            trial_params = QParameters(
                learning_rate_a=params["learning_rate_a"],
                discount_factor_g=params["discount_factor_g"],
                epsilon=params["epsilon"],
                epsilon_decay_rate=params["epsilon_decay_rate"],
                training_episodes=self.base_params.training_episodes,
                play_episodes=self.base_params.play_episodes,
                bruteforce=False,
                skipTraining=False,
                optimize_with_bayesian=False,
                optimize_with_variations=False,
            )
            return {"loss": -self._evaluate_model(trial_params), "status": "ok"}

        space = {
            "learning_rate_a": hp.uniform("learning_rate_a", 0.01, 1.0),
            "discount_factor_g": hp.uniform("discount_factor_g", 0.5, 1.0),
            "epsilon": hp.uniform("epsilon", 0.1, 1.0),
            "epsilon_decay_rate": hp.uniform("epsilon_decay_rate", 0.00001, 0.01),
        }

        trials = Trials()
        best = fmin(
            fn=objective, space=space, algo=tpe.suggest, max_evals=self.base_params.variations_number, trials=trials
        )

        best_params = QParameters(
            learning_rate_a=best["learning_rate_a"],
            discount_factor_g=best["discount_factor_g"],
            epsilon=best["epsilon"],
            epsilon_decay_rate=best["epsilon_decay_rate"],
            training_episodes=self.base_params.training_episodes,
            play_episodes=self.base_params.play_episodes,
            bruteforce=False,
            skipTraining=False,
            optimize_with_bayesian=False,
            optimize_with_variations=False,
        )

        print("\n🏆 Meilleurs hyperparamètres trouvés :")
        self._print_params(best_params)
        return best_params

    def _generate_variation(self) -> QParameters:
        return QParameters(
            learning_rate_a=round(self.base_params.learning_rate_a * random.uniform(0.95, 1.05), 4),
            discount_factor_g=round(self.base_params.discount_factor_g * random.uniform(0.95, 1.05), 4),
            epsilon=round(self.base_params.epsilon * random.uniform(0.9, 1.1), 4),
            epsilon_decay_rate=round(self.base_params.epsilon_decay_rate * random.uniform(0.95, 1.05), 6),
            training_episodes=self.base_params.training_episodes,
            play_episodes=self.base_params.play_episodes,
            bruteforce=False,
            skipTraining=False,
            optimize_with_bayesian=False,
            optimize_with_variations=False,
        )

    def _evaluate_model(self, args: QParameters) -> float:
        results = run(args)
        plotResults(results)
        rewards = [result.rewards for result in results]
        avg_reward = sum(rewards) / len(rewards)
        median_reward = sorted(rewards)[len(rewards) // 2]
        max_reward = max(rewards)
        min_reward = min(rewards)
        score = avg_reward * 0.5 + median_reward * 0.3 + max_reward * 0.2 - (max_reward - min_reward) * 0.1

        self._print_model_stats(args, score, avg_reward, median_reward, max_reward, min_reward)
        return score

    def _print_params(self, args: QParameters):
        print(f"🔹 ##Learning rate (alpha):## {args.learning_rate_a}")
        print(f"🔹 ##Discount factor (gamma):## {args.discount_factor_g}")
        print(f"🔹 ##Exploration rate (epsilon):## {args.epsilon}")
        print(f"🔹 ##Decay rate (epsilon_decay_rate):## {args.epsilon_decay_rate}")
        print(f"🔹 ##Training episodes:## {args.training_episodes}")
        print(f"🔹 ##Play episodes:## {args.play_episodes}")
        print(f"🔹 ##Bruteforce mode:## {'Oui' if args.bruteforce else 'Non'}")
        print(f"🔹 ##Skip training:## {'Oui' if args.skipTraining else 'Non'}")
        print(f"🔹 ##Optimisation bayésienne activée:## {'Oui' if args.optimize_with_bayesian else 'Non'}")
        print(f"🔹 ##Optimisation par variations activée:## {'Oui' if args.optimize_with_variations else 'Non'}")
        print(f"🔹 ##Nombre de variations:## {args.variations_number}")

    def _print_model_stats(
        self,
        args: QParameters,
        score: float,
        avg_reward: float,
        median_reward: float,
        max_reward: float,
        min_reward: float,
    ):
        self._print_params(args)
        print(
            f"🔹##Score: {score:.2f}##\nMoy: {avg_reward:.2f}\n Méd: {median_reward:.2f}\n Max: {max_reward}\n Min: {min_reward}"
        )
