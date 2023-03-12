from typing import Generator, List, NamedTuple, Tuple


class Position(NamedTuple):
    y: int
    x: int


class Board:
    def __init__(self, size, data: List[List[int]] | None = None) -> None:
        self.empty: int = 0
        self.size: int = size
        self.data: List[List[int]] = data or [[self.empty for _ in range(size)] for _ in range(size)]

    def __str__(self) -> str:
        string = ""
        for row in self.data:
            string += str(row)
            string += "\n"
        return string

    def __getitem__(self, key) -> List[int]:
        return self.data[key]

    def __setitem__(self, key, value) -> None:
        self.data[key] = value

    def __iter__(self) -> Generator[List[int], None, None]:
        for row in self.data:
            yield row

    def copy_data(self) -> List[List[int]]:
        data: List[List[int]] = [[x for x in row] for row in self.data]
        return data

    def copy(self):
        data: List[List[int]] = [[x for x in row] for row in self.data]
        return GameBoard(self.size, data=data)

    def len(self) -> int:
        return len(self.data[0])

    def max(self) -> int:
        value_max: int = 0
        for row in self.data:
            if (max_in_row := max(row)) > value_max:
                value_max = max_in_row
        return value_max

    def column_at_index(self, index: int) -> List[int]:
        lenght = self.size
        column: List[int] = []
        for j in range(lenght):
            column.append(self.data[j][index])
        return column

    def columns(self) -> Generator[List[int], None, None]:
        lenght = self.size
        for i in range(lenght):
            column: List[int] = []
            for j in range(lenght):
                column.append(self.data[j][i])
            yield column

    def diagonals_at_pos(self, x: int, y: int) -> Tuple[List[int], List[List[int]]]:
        diagonals: List[List[int]] = []
        positions: List[int] = []
        bdiag: List[int] = []
        fdiag: List[int] = []
        size: int = self.size - 1
        y_fdiag: int = min(x + y, size)
        x_fdiag: int = max(0, (x + y) - (size))
        y_bdiag: int = min(size, y + ((size) - x))
        x_bdiag: int = x + (y_bdiag - y)

        for y_diag, x_diag in zip(range(y_fdiag, -1, -1), range(x_fdiag, self.size)):
            fdiag.append(self.data[y_diag][x_diag])
            if y_diag == y and x_diag == x:
                positions.append(len(fdiag) - 1)

        for y_diag, x_diag in zip(range(y_bdiag, -1, -1), range(x_bdiag, -1, -1)):
            bdiag.append(self.data[y_diag][x_diag])
            if y_diag == y and x_diag == x:
                positions.append(len(bdiag) - 1)

        diagonals.append(fdiag)
        diagonals.append(bdiag)
        return (positions, diagonals)

    def diagonals(self) -> Generator[List[int], None, None]:
        lenght = self.size
        nb_diag = (lenght * 2) - 1
        fdiag: List[List[int]] = [[] for _ in range(nb_diag)]
        bdiag: List[List[int]] = [[] for _ in range(nb_diag)]
        min_bdiag: int = -lenght + 1
        for i in range(lenght):
            for j in range(lenght):
                fdiag[i + j].append(self.data[j][i])
                bdiag[i - j - min_bdiag].append(self.data[j][i])
        for diag in fdiag:
            yield diag
        for diag in bdiag:
            yield diag

    def travel(self) -> Generator[int, None, None]:
        lenght: int = self.size
        for j in range(lenght):
            for i in range(lenght):
                yield self.data[j][i]

    def pos_max_values(self) -> List[Position]:
        positions: List[Position] = []
        value_max: int = self.max()

        for j, row in enumerate(self.data):
            for i, element in enumerate(row):
                if element == value_max:
                    positions.append(Position(j, i))

        return positions


class GameBoard(Board):
    def __init__(self, size, data: List[List[int]] | None = None) -> None:
        self.player: int = 1
        self.ennemy: int = 2
        super().__init__(size, data)

    def add_oponent_turn(self, position: List[str]) -> None:
        self.data[int(position[0])][int(position[1])] = self.ennemy

    def add_player_turn(self, position: Tuple[int, int]) -> None:
        self.data[int(position[0])][int(position[1])] = self.player
