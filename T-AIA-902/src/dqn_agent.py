import random
import collections
import time
from typing import Deque, List, Tuple

import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import gymnasium as gym

from .args import QParameters
from .results import EpisodeResult
from .customEnv import CustomTaxiEnv
from tqdm import trange, tqdm

tqdm._instances.clear()


class QNetwork(nn.Module):
    """Neural network used by the DQN agent."""

    def __init__(
        self,
        input_dim: int,
        output_dim: int,
        hidden_size: int = 128,
        num_passengers: int = 5,
        embedding_dim: int = 4,
        conv_channels: int = 32,
    ) -> None:
        super().__init__()

        self.passenger_embedding = nn.Embedding(num_passengers, embedding_dim)
        self.destination_embedding = nn.Embedding(num_passengers - 1, embedding_dim)

        self.base_input = input_dim - 2 + 2 * embedding_dim

        self.conv = nn.Sequential(
            nn.Conv1d(1, conv_channels, kernel_size=3, padding=1),
            nn.ReLU(),
            nn.Conv1d(conv_channels, conv_channels, kernel_size=3, padding=1),
            nn.ReLU(),
            nn.Dropout(p=0.1),
        )

        conv_out_dim = conv_channels * self.base_input

        self.net = nn.Sequential(
            nn.Linear(conv_out_dim, hidden_size),
            nn.ReLU(),
            nn.Dropout(p=0.2),
            nn.Linear(hidden_size, hidden_size),
            nn.ReLU(),
            nn.Dropout(p=0.2),
            nn.Linear(hidden_size, hidden_size),
            nn.ReLU(),
            nn.Linear(hidden_size, output_dim),
        )

    def forward(self, x):
        passenger_idx = x[:, 2].long()
        dest_idx = x[:, 3].long()

        passenger_emb = self.passenger_embedding(passenger_idx)
        dest_emb = self.destination_embedding(dest_idx)

        other = torch.cat([x[:, :2], x[:, 4:]], dim=1)
        x = torch.cat([other, passenger_emb, dest_emb], dim=1)

        x = x.unsqueeze(1)
        x = self.conv(x)
        x = torch.flatten(x, 1)
        return self.net(x)


class ReplayBuffer:
    def __init__(self, capacity: int = 50_000):
        self.buffer: Deque[Tuple[np.ndarray, int, float, np.ndarray, bool]] = collections.deque(maxlen=capacity)

    def push(self, *transition):
        self.buffer.append(transition)

    def sample(self, batch_size: int):
        batch = random.sample(self.buffer, batch_size)
        s, a, r, ns, d = map(np.array, zip(*batch))
        return (
            torch.tensor(s, dtype=torch.float32),
            torch.tensor(a, dtype=torch.int64).unsqueeze(1),
            torch.tensor(r, dtype=torch.float32).unsqueeze(1),
            torch.tensor(ns, dtype=torch.float32),
            torch.tensor(d, dtype=torch.float32).unsqueeze(1),
        )

    def __len__(self):
        return len(self.buffer)


class DQNAgent:
    def __init__(self, env: gym.Env, _: QParameters):
        self.env = env

        self.gamma = 0.99
        self.lr = 1e-3
        self.epsilon = 1.0
        self.eps_decay = 0.001
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

        self.num_passengers = len(env.locs) + 1

        example_state = self._state_to_tensor(env.encode(0, 0, 0, 0))
        self.state_size = example_state.shape[0]
        self.action_size = env.action_space.n

        self.policy_net = QNetwork(
            self.state_size,
            self.action_size,
            hidden_size=256,
            num_passengers=self.num_passengers,
        ).to(self.device)
        self.target_net = QNetwork(
            self.state_size,
            self.action_size,
            hidden_size=256,
            num_passengers=self.num_passengers,
        ).to(self.device)

        self.target_net.load_state_dict(self.policy_net.state_dict())
        self.target_net.eval()

        self.optimizer = optim.Adam(self.policy_net.parameters(), lr=self.lr)
        self.criterion = nn.MSELoss()
        self.buffer = ReplayBuffer(capacity=10_000)

        self.batch_size = 64
        self.target_update_freq = 1000

    def _state_to_tensor(self, state_idx: int) -> torch.Tensor:
        row, col, pass_idx, dest_idx = self.env.unwrapped.decode(state_idx)
        features = self.env.get_surroundings(row, col, pass_idx, dest_idx)
        return torch.tensor(
            [row / self.env.rows, col / self.env.cols, pass_idx, dest_idx, *features],
            dtype=torch.float32,
            device=self.device,
        )

    def select_action(self, state_idx: int) -> int:
        if random.random() < self.epsilon:
            return random.randrange(self.action_size)
        with torch.no_grad():
            state = self._state_to_tensor(state_idx).unsqueeze(0)
            return self.policy_net(state).argmax(dim=1).item()

    def optimize(self):
        if len(self.buffer) < self.batch_size:
            return

        states, actions, rewards, next_states, dones = self.buffer.sample(self.batch_size)
        states = states.to(self.device)
        next_states = next_states.to(self.device)

        q_values = self.policy_net(states).gather(1, actions.to(self.device))
        with torch.no_grad():
            max_next_q = self.target_net(next_states).max(1, keepdim=True)[0]
            target_q = rewards.to(self.device) + (1 - dones.to(self.device)) * self.gamma * max_next_q

        loss = self.criterion(q_values, target_q)
        self.optimizer.zero_grad()
        loss.backward()
        self.optimizer.step()

    def train(self, episodes: int, map_paths: list[str]) -> List[EpisodeResult]:
        results = []
        global_step = 0
        max_steps = 500

        for ep in trange(episodes, desc="Episodes", position=0):
            map_path = random.choice(map_paths)
            self.env = CustomTaxiEnv(map_path)
            state_idx, _ = self.env.reset()

            result = EpisodeResult(startTime=time.time(), episode=ep)
            total_reward = 0
            done = False

            while not done and result.steps < max_steps:
                action = self.select_action(state_idx)
                next_state_idx, reward, terminated, truncated, _ = self.env.step_hist(action)
                done = terminated or truncated
                total_reward += reward

                self.buffer.push(
                    self._state_to_tensor(state_idx).cpu().numpy(),
                    action,
                    reward,
                    self._state_to_tensor(next_state_idx).cpu().numpy(),
                    done,
                )

                state_idx = next_state_idx
                result.steps += 1
                global_step += 1

                if global_step % 4 == 0:
                    self.optimize()

                if global_step % self.target_update_freq == 0:
                    self.target_net.load_state_dict(self.policy_net.state_dict())

            self.epsilon = max(self.epsilon - self.eps_decay, 0.05)
            result.endTime = time.time()
            result.rewards = total_reward
            result.setup(self.epsilon, self.lr, self.gamma)
            results.append(result)

            if ep % 50 == 0:
                tqdm.write(f"[Ep {ep:5d}] R={total_reward:6.0f}  ε={self.epsilon:.3f}")

        return results

    def play(self, episodes: int, render: bool = False, max_steps: int = 100):
        self.env.render_mode = "human" if render else None
        self.policy_net.eval()

        for ep in trange(episodes, desc="Play episodes"):
            state_idx, _ = self.env.reset()
            done, step = False, 0
            total_reward = 0

            while not done and step < max_steps:
                action = self.policy_net(self._state_to_tensor(state_idx).unsqueeze(0)).argmax().item()

                state_idx, reward, terminated, truncated, _ = self.env.step_hist(action)
                total_reward += reward
                done = terminated or truncated
                step += 1

            if done:
                print(f"✅  Épisode {ep} terminé : reward = {total_reward:+d}, steps = {step}")
            else:
                print(f"⚠️  Épisode {ep} interrompu à {max_steps} steps (agent bloqué)")

        self.env.close()

    def save(self, path: str = "dqn_model.pth"):
        torch.save(self.policy_net.state_dict(), path)

    def load(self, path: str = "dqn_model.pth"):
        self.policy_net.load_state_dict(torch.load(path, map_location=self.device))
        self.policy_net.eval()
