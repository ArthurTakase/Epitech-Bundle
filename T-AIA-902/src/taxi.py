import pickle
import time
from typing import List
import numpy as np
from src.customEnv import CustomTaxiEnv
from src.results import EpisodeResult
from .args import QParameters

CYAN = "\033[96m"
OFF = "\033[0m"


def run(args: QParameters, is_training=True, render=False) -> List[EpisodeResult]:
    env = CustomTaxiEnv(mapPath=args.map_path, render_mode="human" if render else None)

    if is_training:
        q = np.zeros((env.observation_space.n, env.action_space.n))
    else:
        f = open("taxi.pkl", "rb")
        q = pickle.load(f)
        f.close()

    learning_rate_a = args.learning_rate_a
    discount_factor_g = args.discount_factor_g
    epsilon = args.epsilon
    epsilon_decay_rate = args.epsilon_decay_rate
    rng = np.random.default_rng()

    results: List[EpisodeResult] = []
    episodes = args.training_episodes if is_training else args.play_episodes

    for i in range(episodes):
        state = env.reset()[0]
        terminated = False
        truncated = False
        episodeResult: EpisodeResult = EpisodeResult(startTime=time.time(), episode=i)
        episodeResult.setup(epsilon, learning_rate_a, discount_factor_g)
        rewards = 0

        while not terminated and not truncated:
            episodeResult.steps += 1

            if is_training and rng.random() < epsilon:
                action = env.action_space.sample()  # actions: 0=left,1=down,2=right,3=up
            else:
                action = np.argmax(q[state, :])

            new_state, reward, terminated, truncated, _ = env.step(action)
            rewards += reward

            if is_training:
                q[state, action] += learning_rate_a * (
                    reward + discount_factor_g * np.max(q[new_state, :]) - q[state, action]
                )

            state = new_state

        epsilon = max(epsilon - epsilon_decay_rate, 0)

        if epsilon == 0:
            learning_rate_a = 0.0001

        episodeResult.endTime = time.time()
        episodeResult.rewards = rewards
        results.append(episodeResult)

        if is_training and i % 100 == 0:
            print(f"{CYAN}Episode {i + 1}{OFF} rewards: {rewards}, epsilon: {epsilon:.2f}")

    env.close()

    if is_training:
        f = open("taxi.pkl", "wb")
        pickle.dump(q, f)
        f.close()

    return results
