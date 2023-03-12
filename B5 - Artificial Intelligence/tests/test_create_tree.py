from typing import List

from src.ai_min_max import AIMinMax
from src.board import GameBoard
from src.tree import Tree

AI: AIMinMax = AIMinMax()


def test_create_tree_basic():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 2, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data

    tree: Tree = Tree(board=board, ai=AI)
    assert len(tree.children) == 4
    assert len(tree.children[0].children) == 1
    assert len(tree.children[1].children) == 1
    assert len(tree.children[2].children) == 1
    assert len(tree.children[3].children) == 1


def test_create_tree_win1():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0],
    ]
    board.data = data

    tree: Tree = Tree(board=board, ai=AI)
    assert len(tree.children) == 1


def test_create_tree_ennemy_will_win():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 2],
        [0, 0, 0, 2, 1],
        [0, 1, 2, 0, 0],
        [0, 2, 0, 0, 0],
        [0, 1, 0, 0, 0],
    ]
    board.data = data

    tree: Tree = Tree(board=board, ai=AI)
    assert len(tree.children) == 1
    assert tree.children[0].pos == (4, 0)


def test_create_tree_ennemy_3_align():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 2, 0],
        [0, 1, 2, 0, 0],
        [0, 2, 0, 0, 0],
        [0, 1, 0, 0, 0],
    ]
    board.data = data

    tree: Tree = Tree(board=board, ai=AI)
    assert len(tree.children) == 1
    assert tree.children[0].pos == (4, 0)


def test_create_tree_ennemy_3_align2():
    board: GameBoard = GameBoard(5)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0],
        [0, 0, 0, 2, 1],
        [0, 1, 2, 0, 0],
        [0, 2, 0, 0, 0],
        [0, 1, 0, 0, 0],
    ]
    board.data = data

    tree: Tree = Tree(board=board, ai=AI)
    assert len(tree.children) == 2
    assert tree.children[1].pos == (4, 0)
    assert tree.children[0].pos == (0, 4)


def test_create_tree_ennemy_will_win_big():
    board: GameBoard = GameBoard(20)
    data: List[List[int]] = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ]
    board.data = data
    expected = (12, 6)

    tree: Tree = Tree(board=board, ai=AI)
    print(AI.add_weights(board, 1))
    assert len(tree.children) == 1
    assert tree.children[0].pos == expected
