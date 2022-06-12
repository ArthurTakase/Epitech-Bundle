from src.display import display_binomial
from typing import List


def fact(n: int) -> int:
    res: int = 1
    fact: List[int] = [x for x in range(1, n + 1)]
    for nb in fact:
        res *= nb
    return res


def binomial(n: int, k: int) -> float:
    return (fact(n)) / (fact(k) * fact(n - k))


def binomial_int(n: int, k: int) -> int:
    return (fact(n)) // (fact(k) * fact(n - k))


def binomial_computation(n: int, k: int) -> int:
    res: int = binomial_int(n, k)
    display_binomial(n, k, res)
    return 0
