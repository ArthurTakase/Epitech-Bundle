from sys import exit, stdin
from typing import Callable, Dict, List, Tuple

from src.ai import AI
from src.api import API
from src.board import GameBoard, Position
from src.tree import Tree


class Gomoku:
    def __init__(self, ai: AI, api: API = API(), depth: int = 5) -> None:
        self.cmd: Dict[str, Callable] = {
            "START": self.start,
            "TURN": self.turn,
            "BEGIN": self.begin,
            "BOARD": self.board_cmd,
            "INFO": self.info,
            "END": self.end,
            "ABOUT": self.about,
        }
        self.board: GameBoard | None = None
        self.min_size: int = 5
        self.max_size: int = 20
        self.api: API = api
        self.ai: AI = ai
        self.player: int = 1
        self.ennemy: int = 2
        self.depth: int = depth

    def run_cmd(self, command: List[str]) -> None:
        try:
            if command[0] in self.cmd:
                self.cmd[command[0]](command[1:])
            else:
                self.api.send_error(f"Unknown command '{command[0]}'")
        except Exception as e:
            self.api.send_error(f"Error while executing command '{command}' : {e}")

    def play(self) -> None:
        if self.board is None:
            return
        next_move: Tuple[int, int] = self.__next_move()
        self.board.add_player_turn(next_move)
        self.api.send_command(f"{next_move[0]},{next_move[1]}")

    def __next_move(self) -> Position:
        if self.board is None:
            return Position(-1, -1)
        return Tree(board=self.board, ai=self.ai, max_depth=self.depth).solve()

    def start(self, command: List[str]) -> None:
        size: int = 0
        try:
            size = int(command[0])
        except ValueError:
            self.api.send_error(f"Invalid board size '{command[0]}'")

        if size < self.min_size or size > self.max_size:
            self.api.send_error(f"Given size is {size} but must be >= {self.min_size} and <= {self.max_size}")

        self.board = GameBoard(size)
        self.api.send_command("OK")

    def turn(self, command: List[str]) -> None:
        ennemy_pos: List[str] = command[0].split(",")
        if self.board is None:
            return

        try:
            self.board.add_oponent_turn(ennemy_pos)
        except ValueError:
            self.api.send_error(f"Invalid ennemy position '{command[0]}'")

        self.play()

    def begin(self, _) -> None:
        if self.board is None:
            return

        next_move: Tuple[int, int] = (self.board.size // 2, self.board.size // 2)
        self.board.add_player_turn(next_move)
        self.api.send_command(f"{next_move[0]},{next_move[1]}")

    def board_cmd(self, _) -> None:
        line: str = stdin.readline()

        while not line.startswith("DONE"):
            pos: List[str] = line.strip().split(",")
            try:
                if self.board is None:
                    return
                self.board[int(pos[0])][int(pos[1])] = int(pos[2])
            except ValueError:
                self.api.send_error(f"Invalid board position '{line.strip()}'")
            line = stdin.readline()

        self.play()

    def info(self, _) -> None:
        pass

    def end(self, _) -> None:
        exit(0)

    def about(self, _) -> None:
        self.api.send_command(
            'name="GomokuEpitech", version="0.1", author="Arthur_Decaen;Corentin_Roy", country="France"'
        )
