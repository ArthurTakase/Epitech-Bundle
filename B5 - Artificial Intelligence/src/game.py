from typing import List

from src.board import Board


class Game:
    def __init__(self) -> None:
        pass

    def is_win(self, board: Board) -> int:
        if res_win_in_row := self.__win_in_row(board):
            return res_win_in_row

        if res_win_in_column := self.__win_in_column(board):
            return res_win_in_column

        if res_win_in_diagonal := self.__win_in_diagonal(board):
            return res_win_in_diagonal
        return 0

    def player_has_won(self, board: Board) -> int:
        return self.is_win(board) == 1

    def ennemy_has_won(self, board: Board) -> int:
        return self.is_win(board) == 2

    def __win_in_row(self, board: Board) -> int:
        for row in board:
            if row_result := self.is_line_win(row):
                return row_result
        return 0

    def __win_in_column(self, board: Board) -> int:
        for column in board.columns():
            if column_result := self.is_line_win(column):
                return column_result
        return 0

    def __win_in_diagonal(self, board: Board) -> int:
        for diagonal in board.diagonals():
            if diagonals_result := self.is_line_win(diagonal):
                return diagonals_result
        return 0

    def is_line_win(self, line_list: List[int]):
        line: str = "".join(map(str, line_list))
        if line.find("11111") != -1:
            return 1

        if line.find("22222") != -1:
            return 2
        return 0
