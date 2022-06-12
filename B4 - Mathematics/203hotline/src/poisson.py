from math import exp
from src.binomial import fact


def poisson(k: int, _lambda: float) -> float:
    return ((_lambda**k) / fact(k)) * (exp(-_lambda))
