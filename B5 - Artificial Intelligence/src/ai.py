from src.board import Board, GameBoard


class AI:
    def __init__(self) -> None:
        self.player: int = 1
        self.ennemy: int = 2

    def add_weights(self, board_base: GameBoard, _: int) -> Board:
        return board_base
