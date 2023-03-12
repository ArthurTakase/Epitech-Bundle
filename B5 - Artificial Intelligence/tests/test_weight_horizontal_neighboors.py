from typing import List
from src.ai_min_max import AIMinMax
from src.board import GameBoard, Position

AI: AIMinMax = AIMinMax()


def test_weight_horizontal_neighboors_basic1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 1)
    expected: int = 6

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) == expected


def test_weight_horizontal_neighboors_basic2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 1, 1, 1],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 1)
    expected: int = 12

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) == expected


def test_weight_horizontal_neighboors_basic3():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 0)
    expected: int = 0

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) == expected


def test_weight_horizontal_neighboors_basic4():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [1, 0, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 1)
    expected: int = 8

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) == expected


def test_weight_horizontal_neighboors_basic5():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [1, 0, 1, 1, 1],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 1)
    expected: int = 500

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) >= expected


def test_weight_horizontal_neighboors_basic6():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [1, 0, 2, 1, 1],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 1)
    expected: int = 3

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) >= expected


def test_weight_horizontal_neighboors_basic7():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [1, 0, 2, 2, 2],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 1)
    expected: int = 5

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) >= expected


def test_weight_horizontal_neighboors_ennemy_win():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [2, 0, 2, 2, 2],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 1)
    expected: int = 40

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) >= expected


def test_weight_horizontal_neighboors_ennemy_win2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [2, 2, 2, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 4)
    expected: int = 40

    assert AI._AIMinMax__weight_horizontal_neighboors(board, pos, 1) >= expected
