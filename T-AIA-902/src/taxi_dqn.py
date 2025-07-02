from src.dqn_agent import DQNAgent, ReplayBuffer
from src.results import plotResults, plotTest
from src.customEnv import CustomTaxiEnv
from src.args import QParameters


def run_deep_q(args: QParameters):
    env = CustomTaxiEnv(mapPath=args.map_path)
    agent = DQNAgent(env, args)

    if not args.skipTraining:
        print("🔧  Entraînement Deep Q‑Learning…")
        train_stats = agent.train(args.training_episodes, [args.map_path])
        agent.save()
        plotTest(train_stats)
    else:
        print("📂  Chargement du modèle...")
        agent.load("dqn_multi_map.pth" if args.multi_map_model else "dqn_model.pth")
        if args.map_path is None:
            agent.env = CustomTaxiEnv(mapPath="maps/10x10.map")
        else:
            agent.env = CustomTaxiEnv(mapPath=args.map_path)

    print("🎮  Phase play…")
    agent.play(args.play_episodes, render=True)


from typing import List


def train_on_multiple_maps(map_paths: List[str], episodes_per_map: int, args: QParameters):
    from src.dqn_agent import DQNAgent
    from src.results import plotResults
    from src.customEnv import CustomTaxiEnv

    all_results = []
    agent = None

    total_episodes = len(map_paths) * episodes_per_map
    eps_decay = (1.0 - 0.05) / total_episodes
    print(f"decay d'epsilon : {eps_decay:.6f} par épisode")

    print(f"\n🌍 Entraînement multi‑carte sur {len(map_paths)} cartes")
    env = CustomTaxiEnv(mapPath=map_paths[0])
    agent = DQNAgent(env, args)
    agent.eps_decay = eps_decay

    stats = agent.train(len(map_paths) * episodes_per_map, map_paths)
    all_results.extend(stats)

    agent.save("dqn_multi_map.pth")
    print("✅ Modèle sauvegardé dans dqn_multi_map.pth")
    plotResults(all_results)

    test_map = "tester/5x5_test.map"
    print(f"\n🧪 Test du modèle sur : {test_map}")
    agent.env = CustomTaxiEnv(mapPath=test_map)
    agent.play(episodes=args.play_episodes, render=False)
