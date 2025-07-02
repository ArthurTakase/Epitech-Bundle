import time
from typing import List, Tuple
import gymnasium as gym
from src.args import QParameters
from src.results import plotResultBruteforce, BruteforceReturn
from src.customEnv import CustomTaxiEnv

MOVE_DOWN, MOVE_UP, MOVE_RIGHT, MOVE_LEFT, PICKUP, DROPOFF = range(6)
DICT_ACTIONS = {0: "⬇️", 1: "⬆️", 2: "➡️", 3: "⬅️", 4: "👩", 5: "🏢"}
DICT_REWARDS = {-1: "❌", -10: "❌", 20: "✅"}
CYAN = "\033[96m"
OFF = "\033[0m"
BG_CYAN = "\033[46m"


class BruteforceMultiple:
    def __init__(self, args: QParameters, nbToLaunch: int, render_mode=None) -> None:
        self.nbToLaunch = nbToLaunch
        self.allData: List[BruteforceReturn] = []
        self.render_mode = render_mode
        self.args = args

    def launch(self):
        for i in range(self.nbToLaunch):
            print(f"\n{BG_CYAN}🔍 Lancement de la recherche bruteforce {i + 1} sur {self.nbToLaunch}...{OFF}")
            bruteforce = Bruteforce(self.args, self.render_mode)
            data: BruteforceReturn = bruteforce.launch()
            self.allData.append(data)

        plotResultBruteforce(self.allData)


class Bruteforce:
    def __init__(self, args: QParameters, render_mode=None) -> None:
        self.env: gym.Env = CustomTaxiEnv(mapPath=args.map_path, render_mode=render_mode)
        self.steps: int = 0
        self.obstacles = set()
        self.visited = set()
        self.clientDropoff: bool = False
        self.rewards: int = 0
        self.invertDirections = {
            MOVE_DOWN: MOVE_UP,
            MOVE_UP: MOVE_DOWN,
            MOVE_RIGHT: MOVE_LEFT,
            MOVE_LEFT: MOVE_RIGHT,
        }
        self.previousPositions: List[int] = []
        self.fromHistory: bool = False

        state = self.env.reset()[0]

        self.rows, self.cols = self.env.unwrapped.desc.shape
        self.rows -= 2
        self.cols //= 2
        self.totalMapPositions = self.rows * self.cols

        taxi_row, taxi_col, _, _ = self.env.unwrapped.decode(state)
        self.taxiPos = (taxi_row, taxi_col)

    def isInBounds(self, pos: Tuple[int, int]) -> bool:
        return 0 <= pos[0] < self.rows and 0 <= pos[1] < self.cols

    def nextActionDropClient(self) -> int:
        if self.clientDropoff:
            self.clientDropoff = False
            return PICKUP
        if self.taxiPos not in self.visited:
            self.visited.add(self.taxiPos)
            self.clientDropoff = True
            return DROPOFF
        return self.nextActionMove()

    def nextActionGetClient(self) -> int:
        if self.taxiPos not in self.visited:
            self.visited.add(self.taxiPos)
            return PICKUP
        return self.nextActionMove()

    def nextActionMove(self) -> int:
        for action, (dx, dy) in zip([MOVE_DOWN, MOVE_UP, MOVE_RIGHT, MOVE_LEFT], [(1, 0), (-1, 0), (0, 1), (0, -1)]):
            new_pos = (self.taxiPos[0] + dx, self.taxiPos[1] + dy)
            currentSet = frozenset({self.taxiPos, new_pos})

            if self.isInBounds(new_pos) and currentSet not in self.obstacles and new_pos not in self.visited:
                self.fromHistory = False
                return action

        if self.previousPositions:
            action = self.previousPositions.pop()
            self.fromHistory = True
            return action

        return -1

    def nextMovePos(self, pos: Tuple[int, int], action: int) -> Tuple[int, int]:
        if action == MOVE_DOWN:
            return (pos[0] + 1, pos[1])
        if action == MOVE_UP:
            return (pos[0] - 1, pos[1])
        if action == MOVE_LEFT:
            return (pos[0], pos[1] - 1)
        if action == MOVE_RIGHT:
            return (pos[0], pos[1] + 1)
        return pos

    def executeAction(self, action: int) -> Tuple[int, int, bool]:
        state, reward, _, truncated, _ = self.env.step(action)
        self.steps += 1
        self.rewards += reward

        lastPos = self.taxiPos
        taxi_row, taxi_col, _, _ = self.env.unwrapped.decode(state)
        self.taxiPos = (taxi_row, taxi_col)

        if action in [MOVE_DOWN, MOVE_UP, MOVE_RIGHT, MOVE_LEFT]:
            if lastPos == self.taxiPos:
                nextMovePosisition = self.nextMovePos(self.taxiPos, action)
                mySet = frozenset({self.taxiPos, nextMovePosisition})
                self.obstacles.add(mySet)
            elif not self.fromHistory:
                self.previousPositions.append(self.invertDirections[action])

        return state, reward, truncated

    def getClient(self) -> None:
        while True:
            action: int = self.nextActionGetClient()
            if action == -1:
                break

            state, reward, truncated = self.executeAction(action)

            taxi_row, taxi_col, _, _ = self.env.unwrapped.decode(state)
            self.taxiPos = (taxi_row, taxi_col)

            if reward == -1 and action == PICKUP:
                print(f"{CYAN}CLIENT RECUPERE{OFF}")
                break

            if len(self.visited) >= self.totalMapPositions:
                break
            if truncated:
                break

    def dropClient(self) -> None:
        self.visited = set()

        while True:
            action: int = self.nextActionDropClient()
            if action == -1:
                break

            state, reward, truncated = self.executeAction(action)

            taxi_row, taxi_col, _, _ = self.env.unwrapped.decode(state)
            self.taxiPos = (taxi_row, taxi_col)

            if reward == 20:
                print(f"{CYAN}CLIENT DEPOSE{OFF}")
                break

            if len(self.visited) >= self.totalMapPositions:
                break
            if truncated:
                break

    def drawResult(self) -> None:
        self.env.close()

        self.endTime = time.time()
        print(f"{CYAN}Nombre d'étapes:{OFF} {self.steps}")
        print(f"{CYAN}Rewards:{OFF} {self.rewards}")
        print(f"{CYAN}Temps d'exécution:{OFF} {self.endTime - self.startTime:.2f} secondes")

    def launch(self) -> BruteforceReturn:
        self.startTime = time.time()
        self.getClient()
        self.dropClient()
        self.drawResult()
        duration: float = self.endTime - self.startTime
        if duration < 0.5:
            duration = self.steps * 0.25
        return BruteforceReturn(self.steps, self.rewards, duration)
