from itertools import product
from typing import List, Tuple

from src.ai import AI
from src.board import Board, GameBoard, Position


class AIMinMax(AI):
    def __init__(self) -> None:
        super().__init__()

    def add_weights(self, board_base: GameBoard, target: int) -> Board:
        board = GameBoard(board_base.size)

        lenght: int = board_base.len()
        for j, i in product(range(lenght), range(lenght)):
            if board_base.data[j][i] == 0 and self.__has_neighboors(board_base, Position(j, i)):
                board[j][i] = self.__get_weight(board_base, Position(j, i), target)
        return board

    def __get_weight(self, board: GameBoard, pos: Position, target: int) -> int:
        weight: int = 0

        weight += self.__weight_vertical_neighboors(board, pos, target)
        weight += self.__weight_horizontal_neighboors(board, pos, target)
        weight += self.__weight_diagonal_neighboors(board, pos, target)

        return weight

    def __weight_vertical_neighboors(self, board: GameBoard, pos: Position, target: int) -> int:
        ennemy: int = 1 if target == 2 else 2
        weight: int = 0

        line = [x for x in board.column_at_index(pos.x)]
        line[pos.y] = target
        if result := self.__specific_case(line, target, pos.y, ennemy):
            return result
        weight += self.__line_weight(line, pos.y)
        return weight

    def __weight_horizontal_neighboors(self, board: GameBoard, pos: Position, target: int) -> int:
        ennemy: int = 1 if target == 2 else 2
        weight: int = 0

        line = [x for x in board[pos.y]]
        line[pos.x] = target
        if result := self.__specific_case(line, target, pos.x, ennemy):
            return result
        weight += self.__line_weight(line, pos.x)
        return weight

    def __weight_diagonal_neighboors(self, board: GameBoard, pos: Position, target: int) -> int:
        ennemy: int = 1 if target == 2 else 2
        position: int = 0
        weight: int = 0

        diagonales: Tuple[List[int], List[List[int]]] = board.diagonals_at_pos(pos.x, pos.y)
        lines: List[List[int]] = [x for x in diagonales[1]]
        positions: List[int] = diagonales[0]
        for line, position in zip(lines, positions):
            line[position] = target
            if result := self.__specific_case(line, target, position, ennemy):
                return result
            weight += self.__line_weight(line, position)
        if result := self.__cross_diagonals(diagonales, target):
            return result + 1
        if result := self.__cross_diagonals(diagonales, ennemy):
            return result
        return weight

    def __line_weight(self, line_list: List[int], pos: int) -> int:
        lenght: int = len(line_list)
        player: str = str(line_list[pos])
        ennemy: str = "1" if player == "2" else "2"
        target1: str | None = str(line_list[pos + 1]) if pos < lenght - 1 else None
        target2: str | None = str(line_list[pos - 1]) if pos > 0 else None
        line: str = "".join(map(str, line_list))
        weight: int = 0
        i: int = 1

        if target1 is not None:
            while pos + i < lenght and (current := line[pos + i]) == target1:
                if current == player:
                    weight += 2 * i
                elif current == ennemy:
                    weight += 1 * i
                i += 1

        if target2 is not None:
            i = 1
            while pos - i >= 0 and (current := line[pos - i]) == target2:
                if current == player:
                    weight += 2 * i
                elif current == ennemy:
                    weight += 1 * i
                i += 1

        return weight

    def __specific_case(
        self,
        line: List[int],
        target: int,
        pos: int,
        ennemy: int,
    ) -> int:
        if self.__win_line(line, target):
            return 500
        elif self.__ennemy_win_line(line.copy(), pos, ennemy):
            return 40
        elif self.__ennemy_could_win_line(line.copy(), pos, ennemy, target):
            return 30
        return 0

    def __win_line(self, line_list: List[int], target: int) -> int:
        line: str = "".join(map(str, line_list))

        return line.find(f"{target}" * 5) != -1

    def __ennemy_win_line(self, line_list: List[int], pos: int, target: int) -> bool:
        line_list[pos] = target
        line: str = "".join(map(str, line_list))

        return line.find(f"{target}" * 5) != -1

    def __ennemy_could_win_line(
        self,
        line_list: List[int],
        pos: int,
        target: int,
        ennemy: int,
    ) -> bool:
        line_list[pos] = target
        line: str = "".join(map(str, line_list))
        lenght: int = len(line_list)
        index = line.find(f"{target}" * 4)
        bloqued = (
            (index > 0 and line_list[index - 1] == ennemy) or (index + 4 < lenght and line_list[index + 4] == ennemy)
            if index != -1
            else False
        )

        return index != -1 and not bloqued

    def __cross_diagonals(self, diagonales: Tuple[List[int], List[List[int]]], target: int) -> int:
        lines: List[List[int]] = [x for x in diagonales[1]]
        fdiag: str = "".join(map(str, lines[0]))
        bdiag: str = "".join(map(str, lines[1]))
        positions: List[int] = diagonales[0]

        if fdiag[positions[0] + 1 :].startswith(f"{target}" * 2) and bdiag[positions[1] + 1 :].startswith(f"{target}" * 2):
            return 40

        if fdiag[: positions[0]][::-1].startswith(f"{target}" * 2) and bdiag[: positions[1]][::-1].startswith(f"{target}" * 2):
            return 40
        return 0

    def __has_neighboors(self, board: Board, pos: Position) -> bool:
        j: int = pos.y
        i: int = pos.x
        lenght: int = board.len()

        clefs = {
            "top": (j - 1, i),
            "bottom": (j + 1, i),
            "left": (j, i - 1),
            "right": (j, i + 1),
            "top_left": (j - 1, i - 1),
            "top_right": (j - 1, i + 1),
            "bottom_left": (j + 1, i - 1),
            "bottom_right": (j + 1, i + 1),
        }

        for clef in clefs:
            j, i = clefs[clef]
            if 0 <= j < lenght and 0 <= i < lenght and board[j][i] != 0:
                return True

        return False
