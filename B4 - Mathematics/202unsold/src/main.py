from typing import List
from src.args import Argument, Laws, Variance
from src.display import display
from src.price_tab import prices_probability, compute_probability
from src.variance import calcul_variance


def main(args: Argument) -> int:
    tabs: List[List[float]] = prices_probability(args)
    laws: Laws = compute_probability(tabs)
    variance: Variance = calcul_variance(laws.x, laws.y)

    display(tabs, laws, variance)
    return 0
