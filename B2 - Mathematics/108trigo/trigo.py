#!/usr/bin/env python3
from argparse import ArgumentParser, Namespace, ArgumentTypeError
from sys import argv
from typing import List
from math import sqrt
from matrice import print_matrix
from calcul import my_exp, my_cos, my_sin, my_cosh, my_sinh


def correct_function(value: str) -> int:
    function_list = ["EXP", "COS", "SIN", "COSH", "SINH"]

    if value not in function_list:
        raise ArgumentTypeError(f"{value} is not a valid argument.")
    return function_list.index(value)


def get_args() -> Namespace:
    parser: ArgumentParser = ArgumentParser()

    parser.add_argument(
        "fonction",
        type=correct_function,
        help="function to be applied, among at least 'EXP', 'COS', 'SIN', 'COSH' and 'SINH'",
    )
    parser.add_argument("a", type=float, nargs="+", help="coefficients of the matrix")

    try:
        args: Namespace = parser.parse_args()
    except SystemExit:
        exit(84)

    return args


def default_matrice(args: List[float]) -> List[List[float]]:
    limit: int = int(sqrt(len(args)))
    matrice: List[List[float]] = []

    for row in range(limit):
        matrice.append([args[row * limit + col] for col in range(limit)])
    return matrice


def main() -> int:
    if len(argv) == 1:
        print("Mauvais nombre d'arguments")
        return 84
    if sqrt(len(argv) - 2) % 1 != 0:
        print("Mauvais nombre d'arguments")
        return 84

    function_list = [my_exp, my_cos, my_sin, my_cosh, my_sinh]
    args: Namespace = get_args()
    matrice: List[List[float]] = default_matrice(args.a)
    # print_matrix(matrice)
    matrice = function_list[args.fonction](matrice)
    print_matrix(matrice)
    return 0
