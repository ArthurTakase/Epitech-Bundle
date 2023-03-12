from typing import List

from src.board import Board

DATA: List[List[int]] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]


def test_at_pos_0_0():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [1]
    expected_bdiag: List[int] = [9, 5, 1]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(0, 0)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_0_1():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [4, 2]
    expected_bdiag: List[int] = [8, 4]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(0, 1)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_0_2():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [7, 5, 3]
    expected_bdiag: List[int] = [7]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(0, 2)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_1_0():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [4, 2]
    expected_bdiag: List[int] = [6, 2]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(1, 0)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_1_1():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [7, 5, 3]
    expected_bdiag: List[int] = [9, 5, 1]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(1, 1)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_1_2():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [8, 6]
    expected_bdiag: List[int] = [8, 4]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(1, 2)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_2_0():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [7, 5, 3]
    expected_bdiag: List[int] = [3]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(2, 0)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_2_1():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [8, 6]
    expected_bdiag: List[int] = [6, 2]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(2, 1)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"


def test_at_pos_2_2():
    board = Board(3)
    board.data = DATA
    expected_fdiag: List[int] = [9]
    expected_bdiag: List[int] = [9, 5, 1]

    actual_diagonals: List[List[int]] = board.diagonals_at_pos(2, 2)[1]

    assert actual_diagonals[0] == expected_fdiag, "fdiag"
    assert actual_diagonals[1] == expected_bdiag, "bdiag"
