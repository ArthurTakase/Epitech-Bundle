from math import factorial

from src.args import Number


def bernstein(n: int, k: int, t: Number) -> float:
    return binomial_coefficient(n, k) * ((1 - t) ** (n - k)) * (t**k)


def binomial_coefficient(n: int, k: int) -> float:
    return factorial(n) / (factorial(k) * factorial(n - k))
