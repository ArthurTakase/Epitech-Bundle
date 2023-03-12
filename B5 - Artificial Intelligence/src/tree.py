from typing import List

from src.ai import AI
from src.board import Board, GameBoard, Position
from src.game import Game


class Tree:
    def __init__(self, board: GameBoard, ai: AI, max_depth: int = 5) -> None:
        self.board: GameBoard = board
        self.children: List[Node] = []
        self.max_depth: int = max_depth
        self.depth: int = 1
        self.ai: AI = ai
        self.type: int = 1
        self.game: Game = Game()

        self.create_children()

    def create_children(self):
        if self.depth > self.max_depth or self.game.is_win(self.board):
            return

        weights: Board = self.ai.add_weights(self.board, self.type)
        for pos in weights.pos_max_values():
            new_data: List[List[int]] = self.board.copy_data()
            new_data[pos.y][pos.x] = self.type
            self.children.append(
                Node(
                    board=GameBoard(self.board.size, data=new_data),
                    ai=self.ai,
                    depth=self.depth + 1,
                    type=(2 if self.type == 1 else 1),
                    max_depth=self.max_depth,
                    pos=pos,
                )
            )

    def solve(self) -> Position:
        value_max: int = 0
        pos: Position = Position(0, 0)
        for child in self.children:
            if child.solve() > value_max:
                pos: Position = child.pos
        return pos


class Node(Tree):
    def __init__(
        self,
        board: GameBoard,
        ai: AI,
        depth: int,
        type: int,
        pos: Position,
        max_depth: int = 5,
    ) -> None:
        self.board: GameBoard = board
        self.ai: AI = ai
        self.depth: int = depth
        self.type: int = type
        self.max_depth: int = max_depth
        self.weight: int = 0
        self.children: List[Node] = []
        self.game: Game = Game()
        self.pos: Position = pos

        self.create_children()

    def create_children(self):
        super(Node, self).create_children()

    def solve(self) -> int:
        if len(self.children) == 0:
            self.weight = self.ai.add_weights(self.board, self.type).max()
            return self.weight

        values: List[int] = [child.solve() for child in self.children]

        return max(values) if self.type == 1 else min(values)
