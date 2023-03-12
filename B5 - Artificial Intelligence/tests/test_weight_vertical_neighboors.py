from typing import List

from src.ai_min_max import AIMinMax
from src.board import GameBoard, Position

AI: AIMinMax = AIMinMax()


def test_weight_vertical_neighboors_basic1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(3, 3)
    expected: int = 6

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) == expected


def test_weight_vertical_neighboors_basic2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(4, 3)
    expected: int = 12

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) == expected


def test_weight_vertical_neighboors_win():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(4, 3)
    expected: int = 500

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) >= expected


def test_weight_vertical_neighboors_basic3():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 1, 0],
        [0, 0, 1, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(3, 2)
    expected: int = 0

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) == expected


def test_weight_vertical_neighboors_basic4():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 1, 0],
        [0, 0, 1, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 2

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) == expected


def test_weight_vertical_neighboors_basic5():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
    ]
    board.data = data
    pos: Position = Position(3, 3)
    expected: int = 500

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) == expected


def test_weight_vertical_neighboors_basic_with_ennemy1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(4, 3)
    expected: int = 1

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) == expected


def test_weight_vertical_neighboors_basic_with_ennemy2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 3)
    expected: int = 7

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) == expected


def test_weight_vertical_neighboors_ennemy_win():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 2, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 2, 0],
    ]
    board.data = data
    pos: Position = Position(2, 3)
    expected: int = 40

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) >= expected


def test_weight_vertical_neighboors_ennemy_win2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 2, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(4, 3)
    expected: int = 40

    assert AI._AIMinMax__weight_vertical_neighboors(board, pos, 1) >= expected
