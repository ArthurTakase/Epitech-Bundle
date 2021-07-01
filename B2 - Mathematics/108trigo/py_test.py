#!/usr/bin/env python3
import pytest as pt
from trigo import *
from matrice import *


def test_correct_function():
    assert correct_function("COS") == 1
    with pt.raises(ArgumentTypeError):
        assert correct_function("arthur") == "arthur is not a valid argument."


def test_my_exp():
    temp = my_exp([[1.0, 2.0], [3.0, 4.0]])
    assert round(temp[0][0], 2) == 51.97
    assert round(temp[0][1], 2) == 74.74
    assert round(temp[1][0], 2) == 112.10
    assert round(temp[1][1], 2) == 164.07


def test_my_cos():
    temp = my_cos([[1.0, 2.0], [3.0, 4.0]])
    assert round(temp[0][0], 2) == 0.86
    assert round(temp[0][1], 2) == -0.11
    assert round(temp[1][0], 2) == -0.17
    assert round(temp[1][1], 2) == 0.69


def test_my_sin():
    temp = my_sin([[1.0, 2.0], [3.0, 4.0]])
    assert round(temp[0][0], 2) == -0.47
    assert round(temp[0][1], 2) == -0.15
    assert round(temp[1][0], 2) == -0.22
    assert round(temp[1][1], 2) == -0.69


def test_my_cosh():
    temp = my_cosh([[1.0, 2.0], [3.0, 4.0]])
    assert round(temp[0][0], 2) == 26.54
    assert round(temp[0][1], 2) == 37.12
    assert round(temp[1][0], 2) == 55.67
    assert round(temp[1][1], 2) == 82.21


def test_my_sinh():
    temp = my_sinh([[1.0, 2.0], [3.0, 4.0]])
    assert round(temp[0][0], 2) == 25.43
    assert round(temp[0][1], 2) == 37.62
    assert round(temp[1][0], 2) == 56.43
    assert round(temp[1][1], 2) == 81.86


def test_default_matrice():
    assert default_matrice([1.0, 2.0, 3.0, 4.0]) == [[1.0, 2.0], [3.0, 4.0]]


def test_new_matrix():
    assert new_matrix(2) == [[0, 0], [0, 0]]
