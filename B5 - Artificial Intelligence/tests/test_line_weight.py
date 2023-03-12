from typing import List
from src.ai_min_max import AIMinMax


def test_weight_0():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [0, 1, 0, 1, 1, 1]
    expected: int = 0

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_2():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [1, 1, 0, 1, 1, 1]
    expected: int = 2

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_3():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [1, 1, 1, 0, 0, 1]
    expected: int = 4

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_4():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [1, 1, 1, 1, 0, 1]
    expected: int = 8

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_50():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [1, 1, 1, 1, 1, 0]
    expected: int = 14

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_50_2():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [1, 1, 1, 1, 1]
    expected: int = 14

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_5():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [2, 1, 2, 1, 0, 1]
    expected: int = 2

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_6():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [2, 1, 2, 2, 0, 1]
    expected: int = 4

    assert ai._AIMinMax__line_weight(line, 1) == expected


def test_weight_7():
    ai: AIMinMax = AIMinMax()
    line: List[int] = [2, 1, 1, 2, 0, 1]
    expected: int = 3

    assert ai._AIMinMax__line_weight(line, 1) == expected
