from typing import List, NamedTuple
import numpy as np
import matplotlib.pyplot as plt

CYAN = "\033[96m"
OFF = "\033[0m"


class BruteforceReturn(NamedTuple):
    steps: int
    rewards: int
    duration: float


class EpisodeResult:
    rewards: float
    steps: int
    startTime: float
    endTime: float
    episode: int
    epsilon: float
    learning_rate_a: float
    discount_factor_g: float

    def __init__(self, startTime: float, episode: int) -> None:
        self.startTime = startTime
        self.endTime = 0
        self.rewards = 0
        self.steps = 0
        self.episode = episode
        self.epsilon = 0.0
        self.learning_rate_a = 0.0
        self.discount_factor_g = 0.0

    def setup(self, epsilon: float, learning_rate_a: float, discount_factor_g: float) -> None:
        self.epsilon = epsilon
        self.learning_rate_a = learning_rate_a
        self.discount_factor_g = discount_factor_g

    def duration(self) -> float:
        duration = self.endTime - self.startTime
        if duration < 0.1:
            duration = self.steps * 0.25
        return duration


def showResults(results: List[EpisodeResult]) -> None:
    mean_rewards = np.mean([result.rewards for result in results])
    mean_steps = np.mean([result.steps for result in results])
    mean_time = np.mean([result.endTime - result.startTime for result in results])
    print(f"Mean rewards:\t{mean_rewards}")
    print(f"Mean steps:\t{mean_steps}")
    print(f"Mean time:\t{mean_time:.2f}")

    best_episode = max(results, key=lambda result: result.rewards)
    print("\nBest episode:")
    print(f"{CYAN}Episode {best_episode.episode}{OFF} ", end="")
    print(f"rewards: {best_episode.rewards}, ", end="")
    print(f"steps: {best_episode.steps}, ", end="")
    print(f"time: {best_episode.endTime - best_episode.startTime:.2f}")

    print("\nRandom episodes:")
    episodes = results.copy()
    for _ in range(5):
        if len(episodes) == 0:
            break
        random_episode = np.random.choice(episodes)
        episodes.remove(random_episode)

        print(f"{CYAN}Episode {random_episode.episode}{OFF} ", end="")
        print(f"rewards: {random_episode.rewards}, ", end="")
        print(f"steps: {random_episode.steps}, ", end="")
        print(f"time: {random_episode.endTime - random_episode.startTime:.2f}")


def plotResults(results: List[EpisodeResult]) -> None:
    rewards = [result.rewards for result in results]
    steps = [result.steps for result in results]
    time = [result.duration() for result in results]

    mean_rewards = np.mean(rewards)
    mean_steps = np.mean(steps)
    mean_time = np.mean(time)

    fig, ax = plt.subplots(1)
    fig.set_size_inches(11, 7)
    fig.suptitle("Results")
    ax.plot(rewards, label="rewards")
    ax.plot(steps, label="steps")
    ax.plot(time, label="time")
    ax.axhline(mean_rewards, color="r", linestyle="--", label=f"Mean rewards: {mean_rewards:.2f}")
    ax.axhline(mean_steps, color="g", linestyle="--", label=f"Mean steps: {mean_steps:.2f}")
    ax.axhline(mean_time, color="b", linestyle="--", label=f"Mean time: {mean_time:.2f}")
    ax.legend(loc="upper center", bbox_to_anchor=(0.5, -0.15), fancybox=True, shadow=True, ncol=3)
    plt.subplots_adjust(bottom=0.2)

    plt.savefig(
        f"results/playing_results_{results[0].epsilon}_{results[0].learning_rate_a}_{results[0].discount_factor_g}.png"
    )


def plotTest(results: List[EpisodeResult]) -> None:
    rewards = [result.rewards for result in results]
    epsilons = [result.epsilon for result in results]
    learning_rates = [result.learning_rate_a for result in results]
    discount_factors = [result.discount_factor_g for result in results]

    mean_rewards = np.mean(rewards)
    median_rewards = np.median(rewards)

    fig, ax = plt.subplots(2)
    fig.set_size_inches(11, 7)
    fig.suptitle("Test Results")
    ax[0].plot(rewards, label="rewards")
    ax[0].axhline(mean_rewards, color="r", linestyle="--", label=f"Mean: {mean_rewards:.2f}")
    ax[0].axhline(median_rewards, color="g", linestyle="--", label=f"Median: {median_rewards:.2f}")
    ax[0].legend()
    ax[1].plot(epsilons, label="epsilon")
    ax[1].plot(learning_rates, label="learning rate")
    ax[1].plot(discount_factors, label="discount factor")
    ax[1].legend()

    plt.savefig(
        f"results/test_results_{results[0].epsilon}_{results[0].learning_rate_a}_{results[0].discount_factor_g}.png"
    )


def plotResultBruteforce(results: List[BruteforceReturn]):
    rewards = [result.rewards for result in results]
    steps = [result.steps for result in results]
    time = [result.duration for result in results]

    mean_rewards = np.mean(rewards)
    mean_steps = np.mean(steps)
    mean_time = np.mean(time)

    median_rewards = np.median(rewards)
    median_steps = np.median(steps)
    median_time = np.median(time)

    fig, ax = plt.subplots(1)
    fig.suptitle("Bruteforce Results - Rewards")
    fig.set_size_inches(11, 7)
    ax.plot(rewards, label="rewards")
    ax.axhline(mean_rewards, color="r", linestyle="--", label=f"Mean: {mean_rewards:.2f}")
    ax.axhline(median_rewards, color="g", linestyle="--", label=f"Median: {median_rewards:.2f}")
    ax.legend(loc="upper center", bbox_to_anchor=(0.5, -0.15), fancybox=True, shadow=True, ncol=3)
    plt.subplots_adjust(bottom=0.2)
    plt.savefig(f"results/bruteforce_results_reward.png")

    fig, ax = plt.subplots(1)
    fig.suptitle("Bruteforce Results - Steps")
    fig.set_size_inches(11, 7)
    ax.plot(steps, label="steps")
    ax.axhline(mean_steps, color="r", linestyle="--", label=f"Mean: {mean_steps:.2f}")
    ax.axhline(median_steps, color="g", linestyle="--", label=f"Median: {median_steps:.2f}")
    ax.legend(loc="upper center", bbox_to_anchor=(0.5, -0.15), fancybox=True, shadow=True, ncol=3)
    plt.subplots_adjust(bottom=0.2)
    plt.savefig(f"results/bruteforce_results_steps.png")

    fig, ax = plt.subplots(1)
    fig.suptitle("Bruteforce Results - Time")
    fig.set_size_inches(11, 7)
    ax.plot(time, label="time")
    ax.axhline(mean_time, color="r", linestyle="--", label=f"Mean: {mean_time:.2f}")
    ax.axhline(median_time, color="g", linestyle="--", label=f"Median: {median_time:.2f}")
    ax.legend(loc="upper center", bbox_to_anchor=(0.5, -0.15), fancybox=True, shadow=True, ncol=3)
    plt.subplots_adjust(bottom=0.2)
    plt.savefig(f"results/bruteforce_results_time.png")
