from typing import List
from src.ai_min_max import AIMinMax
from src.board import Board, Position, GameBoard

AI: AIMinMax = AIMinMax()


def test_weight_diagonal_neighboors_forward_basic1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 4

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_forward_basic2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 2],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 5

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_forward_basic3():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 2],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0],
        [1, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 9

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_backward_basic1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 1],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 6

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_backward_basic2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [2, 0, 0, 0, 0],
        [0, 2, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 5

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_backward_basic3():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [2, 0, 0, 0, 0],
        [0, 2, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 1],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 9

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_basic1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [2, 0, 0, 0, 2],
        [0, 2, 0, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 1],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 40

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_basic2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [2, 0, 0, 0, 2],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [1, 0, 0, 0, 1],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 41

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_basic3():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(1, 4)
    expected: int = 2

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) == expected


def test_weight_diagonal_neighboors_win1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [2, 0, 0, 0, 1],
        [0, 1, 0, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [1, 0, 0, 0, 1],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 500

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) >= expected


def test_weight_diagonal_neighboors_win2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [1, 0, 0, 0, 1],
        [0, 1, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [1, 0, 0, 0, 1],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 500

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) >= expected


def test_weight_diagonal_neighboors_ennemy_win_forward():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [1, 0, 0, 0, 2],
        [0, 1, 0, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 2, 0, 0, 0],
        [2, 0, 0, 0, 0],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 40

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) >= expected


def test_weight_diagonal_neighboors_ennemy_win_backward():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [2, 0, 0, 0, 2],
        [0, 2, 0, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 2],
    ]
    board.data = data
    pos: Position = Position(2, 2)
    expected: int = 40

    assert AI._AIMinMax__weight_diagonal_neighboors(board, pos, 1) >= expected
