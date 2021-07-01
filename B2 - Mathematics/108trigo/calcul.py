from math import factorial, pow
from matrice import (
    mul_matrix,
    power_matrix,
    divide_matrix,
    substract_matrix,
    add_matrix,
    base_matrix,
    print_matrix,
    new_matrix,
)
from typing import List

MAX_RANGE = 40


def my_exp(matrice: List[List[float]]) -> List[List[float]]:
    temp: List[List[float]] = base_matrix(len(matrice))

    for i in range(1, MAX_RANGE + 1):
        temp = add_matrix(temp, divide_matrix(power_matrix(matrice, i), factorial(i)))
    return temp


def my_cos(matrice: List[List[float]]) -> List[List[float]]:
    temp: List[List[float]] = base_matrix(len(matrice))
    for i in range(1, MAX_RANGE + 1):
        if i % 2 == 0:
            temp = add_matrix(
                temp, divide_matrix(power_matrix(matrice, 2 * i), factorial(2 * i))
            )
        else:
            temp = substract_matrix(
                temp, divide_matrix(power_matrix(matrice, 2 * i), factorial(2 * i))
            )
    return temp


def my_sin(matrice: List[List[float]]) -> List[List[float]]:
    tmp: List[List[float]] = matrice

    for i in range(1, MAX_RANGE + 1):
        if i % 2 == 0:
            tmp = add_matrix(
                tmp,
                divide_matrix(power_matrix(matrice, 2 * i + 1), factorial(2 * i + 1)),
            )
        else:
            tmp = substract_matrix(
                tmp,
                divide_matrix(power_matrix(matrice, 2 * i + 1), factorial(2 * i + 1)),
            )
    return tmp


def my_cosh(matrice: List[List[float]]) -> List[List[float]]:
    temp: List[List[float]] = base_matrix(len(matrice))

    for i in range(1, MAX_RANGE + 1):
        temp = add_matrix(
            temp, divide_matrix(power_matrix(matrice, 2 * i), factorial(2 * i))
        )
    return temp


def my_sinh(matrice: List[List[float]]) -> List[List[float]]:
    temp: List[List[float]] = matrice

    for i in range(1, MAX_RANGE + 1):
        temp = add_matrix(
            temp, divide_matrix(power_matrix(matrice, 2 * i + 1), factorial(2 * i + 1))
        )
    return temp
