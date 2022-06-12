from src.args import Arguments
from src.display import (
    display_density,
    display_percentage_above_qi,
    display_percentage_between_qi,
)
from math import sqrt, pi, exp
from typing import Union, List


def density(u: int, s: int, x: Union[float, int]) -> float:
    return (1 / (s * sqrt(2 * pi))) * exp(-(((x - u) ** 2) / (2 * (s**2))))


def noIQ(args: Arguments) -> List[float]:
    return [density(args.u, args.s, x) for x in range(0, 201)]


def computeIQ(start: int, stop: int, args: Arguments) -> float:
    res: float = 0.0
    i: float = float(start)

    while i < stop:
        res += density(args.u, args.s, i)
        i += 0.01
    return res


def launch205(args: Arguments) -> None:
    if args.IQ1 and args.IQ2:
        percentage_between: float = computeIQ(args.IQ1, args.IQ2, args)
        display_percentage_between_qi(percentage_between, args)
    elif args.IQ1 and not args.IQ2:
        percentage_above: float = computeIQ(0, args.IQ1, args)
        display_percentage_above_qi(percentage_above, args)
    else:
        res: List[float] = noIQ(args)
        display_density(res)
