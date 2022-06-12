from typing import List
from src.args import Argument, Laws


def f(x: int, y: int, a: int, b: int) -> float:
    return ((a - x) * (b - y)) / ((5 * a - 150) * (5 * b - 150))


def generate_tab(a: int, b: int) -> List[List[float]]:
    return [[f(x, y, a, b) for x in range(10, 60, 10)] for y in range(10, 60, 10)]


def compute_probability(tabs: List[List[float]]) -> Laws:
    X_law: List[float] = compute_x_law(tabs)
    Y_law: List[float] = compute_y_sum(tabs)
    return Laws(X_law, Y_law)


def compute_x_law(tabs: List[List[float]]) -> List[float]:
    X_law: List[float] = []
    sum_x: float = 0.0

    for tab in tabs:
        for nb in tab:
            sum_x += nb
        X_law.append(sum_x)
        sum_x = 0
    return X_law


def compute_y_sum(tabs: List[List[float]]) -> List[float]:
    sum_y: float = 0
    Y_law: List[float] = []

    for x in range(5):
        for i in range(5):
            sum_y += tabs[i][x]
        Y_law.append(sum_y)
        sum_y = 0
    return Y_law


def prices_probability(args: Argument) -> List[List[float]]:
    return generate_tab(args.a, args.b)
