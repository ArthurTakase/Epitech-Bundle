from argparse import ArgumentParser, ArgumentTypeError
from typing import NamedTuple
from sys import argv
from typing import List


class QParameters(NamedTuple):
    learning_rate_a: float
    discount_factor_g: float
    epsilon: float
    epsilon_decay_rate: float
    training_episodes: int
    play_episodes: int
    bruteforce: bool
    skipTraining: bool
    optimize_with_bayesian: bool
    optimize_with_variations: bool
    variations_number: int = 10
    map_path: str | None = None
    deep_q: bool = False
    multi_map_model: bool = False


def percentage(string: str) -> float:
    try:
        nb: float = float(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't an float")
    if nb < 0.0 or nb > 1.0:
        raise ArgumentTypeError(f"{string} isn't positive float")
    return nb


def int_positive(string: str) -> int:
    try:
        nb: int = int(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't an int")
    if nb < 0:
        raise ArgumentTypeError(f"{string} isn't positive int")
    return nb


def parse_args(arguments: List[str] = argv[1:]) -> QParameters:
    parser = ArgumentParser(description="./main u s [IQ1] [IQ2]")
    parser.add_argument(
        "--learning_rate_a",
        type=percentage,
        nargs="?",
        default=0.9,
        help="Aplha: taux d'apprentissage",
    )
    parser.add_argument(
        "--discount_factor_g",
        type=percentage,
        nargs="?",
        default=0.9,
        help="Gamma: Importance des récompenses futures",
    )
    parser.add_argument(
        "--epsilon",
        type=percentage,
        nargs="?",
        default=1.0,
        help="Probabilité d'explorer au début",
    )
    parser.add_argument(
        "--epsilon_decay_rate",
        type=percentage,
        nargs="?",
        default=0.0001,
        help="Décroissance d'espsilon",
    )
    parser.add_argument(
        "--training_episodes",
        type=int_positive,
        nargs="?",
        default=15000,
        help="Nombre d'épisodes d'entraînement",
    )
    parser.add_argument(
        "--play_episodes",
        type=int_positive,
        nargs="?",
        default=10,
        help="Nombre d'épisodes de jeu",
    )
    parser.add_argument("--bruteforce", action="store_true", help="Activer le mode bruteforce", default=False)
    parser.add_argument("--skipTraining", action="store_true", help="Skip training", default=False)
    parser.add_argument(
        "--optimize-with-bayesian", action="store_true", help="Activer le mode d'optimisation bayésienne", default=False
    )
    parser.add_argument(
        "--optimize-with-variations",
        action="store_true",
        help="Activer le mode optimisation via des variations aléatoires",
        default=False,
    )
    parser.add_argument(
        "--variations_number",
        type=int_positive,
        nargs="?",
        default=10,
        help="Nombre de variations des hyperparamètres avec le mode optimisation",
    )
    parser.add_argument(
        "--map_path",
        type=str,
        nargs="?",
        default=None,
        help="Chemin vers le fichier de la carte",
    )
    parser.add_argument("--deep_q", action="store_true",
                    help="Utiliser l'agent Deep Q‑Learning", default=False)
    parser.add_argument("--multi_map_model", action="store_true", help="Utiliser le modèle entraîné sur plusieurs maps")


    try:
        args = parser.parse_args(arguments)
        if args.variations_number != 10 and not args.optimize_with_variations | args.optimize_with_bayesian:
            parser.error("--variations_number ne peut être utilisé que si --optimize-with-xxxxx est utilisé.")
    except SystemExit:
        exit(84)
    return QParameters(
        args.learning_rate_a,
        args.discount_factor_g,
        args.epsilon,
        args.epsilon_decay_rate,
        args.training_episodes,
        args.play_episodes,
        args.bruteforce,
        args.skipTraining,
        args.optimize_with_bayesian,
        args.optimize_with_variations,
        args.variations_number,
        args.map_path,
        args.deep_q,
        args.multi_map_model,
    )
