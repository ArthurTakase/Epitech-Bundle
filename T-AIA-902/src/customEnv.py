from gymnasium.envs.toy_text.taxi import TaxiEnv
import numpy as np

from typing import Optional
from gymnasium import spaces

WINDOW_SIZE = (550, 350)
MAX_MAP_SIZE = 10

DEFAULT_MAP = [
    "+---------+",
    "|R: | : :G|",
    "| : | : : |",
    "| : : : : |",
    "| | : | : |",
    "|Y| : |B: |",
    "+---------+",
]


class CustomTaxiEnv(TaxiEnv):
    def __init__(self, mapPath: str | None = None, render_mode: Optional[str] = None):
        self.desc = np.asarray(self.read_map(mapPath) if mapPath is not None else DEFAULT_MAP, dtype="c")
        self.locs = self.extract_locs()

        self.locs_colors = [(255, 0, 0), (0, 255, 0), (255, 255, 0), (0, 0, 255)]

        self.rows = len(self.desc) - 2
        self.cols = (len(self.desc[0]) - 1) // 2

        self.num_states = self.rows * self.cols * (len(self.locs) + 1) * len(self.locs)
        self.initial_state_distrib = np.zeros(self.num_states)
        num_actions = 6
        self.P = {state: {action: [] for action in range(num_actions)} for state in range(self.num_states)}

        for row in range(self.rows):
            for col in range(self.cols):
                for pass_idx in range(len(self.locs) + 1):
                    for dest_idx in range(len(self.locs)):
                        state = self.encode(row, col, pass_idx, dest_idx)
                        if pass_idx < len(self.locs) and pass_idx != dest_idx:
                            self.initial_state_distrib[state] += 1
                        for action in range(num_actions):
                            new_row, new_col, new_pass_idx = row, col, pass_idx
                            reward = -1
                            terminated = False
                            taxi_loc = (row, col)

                            if action == 0:  # south
                                new_row = min(row + 1, self.rows - 1)
                            elif action == 1:  # north
                                new_row = max(row - 1, 0)
                            if action == 2 and self.desc[1 + row, 2 * col + 2] == b":":
                                new_col = min(col + 1, self.cols - 1)
                            elif action == 3 and self.desc[1 + row, 2 * col] == b":":
                                new_col = max(col - 1, 0)
                            elif action == 4:  # pickup
                                if pass_idx < len(self.locs) and taxi_loc == self.locs[pass_idx]:
                                    new_pass_idx = len(self.locs)  # in taxi
                                else:
                                    reward = -10
                            elif action == 5:  # dropoff
                                if (taxi_loc == self.locs[dest_idx]) and pass_idx == len(self.locs):
                                    new_pass_idx = dest_idx
                                    terminated = True
                                    reward = 20
                                elif (taxi_loc in self.locs) and pass_idx == len(self.locs):
                                    new_pass_idx = self.locs.index(taxi_loc)
                                else:
                                    reward = -10

                            new_state = self.encode(new_row, new_col, new_pass_idx, dest_idx)
                            self.P[state][action].append((1.0, new_state, reward, terminated))

        self.initial_state_distrib /= self.initial_state_distrib.sum()
        self.action_space = spaces.Discrete(num_actions)
        self.observation_space = spaces.Discrete(self.num_states)
        self.render_mode = render_mode
        self.s = None
        self.lastaction = None

        # pygame utils
        self.window = None
        self.clock = None
        self.cell_size = (
            WINDOW_SIZE[0] / self.desc.shape[1],
            WINDOW_SIZE[1] / self.desc.shape[0],
        )
        self.taxi_imgs = None
        self.taxi_orientation = 0
        self.passenger_img = None
        self.destination_img = None
        self.median_horiz = None
        self.median_vert = None
        self.background_img = None
        self.prev_positions = []
        self.max_history = 6

    def reset(self, *args, **kwargs):
        """Clear loop history and reset the environment."""
        self.prev_positions.clear()
        return super().reset(*args, **kwargs)

    def encode(self, taxi_row, taxi_col, pass_loc, dest_idx):
        i = taxi_row
        i *= self.cols
        i += taxi_col
        i *= len(self.locs) + 1
        i += pass_loc
        i *= len(self.locs)
        i += dest_idx
        return i

    def decode(self, i):
        dest_idx = i % len(self.locs)
        i //= len(self.locs)
        pass_loc = i % (len(self.locs) + 1)
        i //= len(self.locs) + 1
        taxi_col = i % self.cols
        i //= self.cols
        taxi_row = i
        return taxi_row, taxi_col, pass_loc, dest_idx

    def extract_locs(self):
        locs = []

        for row in range(len(self.desc)):
            if row == 0 or row == len(self.desc) - 1:
                continue
            for col in range(len(self.desc[row])):
                if col == 0 or col == len(self.desc[row]) - 1:
                    continue
                if self.desc[row, col] != b" " and self.desc[row, col] != b":" and self.desc[row, col] != b"|":
                    locs.append((row - 1, col // 2))

        return locs

    def read_map(self, map_path: str):
        with open(map_path, "r") as f:
            map_data = [line.rstrip("\n") for line in f]
        return map_data

    def get_possible_moves(self, row: int, col: int) -> list[int]:
        """
        Retourne [can_go_south, north, east, west] (1 = oui, 0 = bloqué)
        """
        desc = self.desc

        can_go_south = int(row < self.rows - 1)
        can_go_north = int(row > 0)
        can_go_east  = int(desc[1 + row, 2 * col + 2] == b":")
        can_go_west  = int(desc[1 + row, 2 * col] == b":")

        return [can_go_south, can_go_north, can_go_east, can_go_west]
    

    def step_hist(self, action: int):
        """Perform a normal step and apply a loop penalty."""
        s, reward, terminated, truncated, info = super().step(action)

        taxi_row, taxi_col, _, _ = self.decode(s)
        curr_pos = (taxi_row, taxi_col)
        self.prev_positions.append(curr_pos)
        if len(self.prev_positions) > self.max_history:
            self.prev_positions.pop(0)

        if len(self.prev_positions) >= 2 and self.prev_positions[-1] == self.prev_positions[-2]:
            reward -= 3
        elif self.prev_positions.count(curr_pos) >= 3:
            reward -= 2

        if len(self.prev_positions) >= 4:
            if (
                self.prev_positions[-1] == self.prev_positions[-3]
                and self.prev_positions[-2] == self.prev_positions[-4]
            ):
                reward -= 5

        return s, reward, terminated, truncated, info

    
    def get_surroundings(self, row, col, pass_idx, dest_idx):
        passenger_row, passenger_col = self.locs[pass_idx] if pass_idx < len(self.locs) else (-1, -1)
        destination_row, destination_col = self.locs[dest_idx]

        rel_passenger = [
            (passenger_row - row) / self.rows if passenger_row != -1 else 0.0,
            (passenger_col - col) / self.cols if passenger_col != -1 else 0.0,
            int(pass_idx == len(self.locs))
        ]
        rel_destination = [
            (destination_row - row) / self.rows,
            (destination_col - col) / self.cols
        ]

        possible_moves = self.get_possible_moves(row, col)

        return rel_passenger + rel_destination + possible_moves
    
    def get_full_view(self, row: int, col: int, pass_idx: int, dest_idx: int) -> list[int]:
        """Return a flattened representation of the entire map.

        For every cell in a MAX_MAP_SIZE x MAX_MAP_SIZE grid, we encode:
        [south, north, east, west, is_taxi, has_passenger, is_destination].
        Cells outside the actual map are padded with zeros. A final flag
        indicates whether the passenger is already in the taxi.
        """
        passenger_pos = self.locs[pass_idx] if pass_idx < len(self.locs) else (-1, -1)
        destination_pos = self.locs[dest_idx]

        features: list[int] = []
        for r in range(MAX_MAP_SIZE):
            for c in range(MAX_MAP_SIZE):
                if r < self.rows and c < self.cols:
                    moves = self.get_possible_moves(r, c)
                    is_taxi = int((r, c) == (row, col))
                    has_passenger = int(passenger_pos == (r, c))
                    is_destination = int(destination_pos == (r, c))
                    features.extend(moves + [is_taxi, has_passenger, is_destination])
                else:
                    features.extend([0, 0, 0, 0, 0, 0, 0])

        features.append(int(pass_idx == len(self.locs)))
        return features



