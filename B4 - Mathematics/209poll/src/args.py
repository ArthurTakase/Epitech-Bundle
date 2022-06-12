from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List, NamedTuple, Tuple

Interval = Tuple[float, float]


class Result(NamedTuple):
    pSize: int
    sSize: int
    P: float
    variance: float
    confidence_interval_95: Interval
    confidence_interval_99: Interval


class Arguments(NamedTuple):
    pSize: int
    sSize: int
    P: float


def pourcent(string: str) -> float:
    try:
        nb: float = float(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't a number")
    if nb < 0:
        raise ArgumentTypeError(f"{string} is too small")
    if nb > 100:
        raise ArgumentTypeError(f"{string} is too big")
    return nb


def postitive_int(string: str) -> int:
    try:
        nb: int = int(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't an integer")
    if nb < 0:
        raise ArgumentTypeError(f"{string} isn't a postive integer")
    return nb


def parse_args(args: List[str] = argv[1:]) -> Arguments:
    parser = ArgumentParser()
    parser.add_argument("pSize", type=postitive_int,
                        help="size of the population")
    parser.add_argument(
        "sSize",
        type=postitive_int,
        help="size of the sample (supposed to be representative)",
    )
    parser.add_argument(
        "P",
        type=pourcent,
        help="percentage of voting intentions for a specific candidate",
    )

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)

    if (arguments.pSize < arguments.sSize):
        print("usage: 209poll [-h] pSize sSize P")
        print("209: error: The population size must be greater than the sample size")
        exit(84)

    return Arguments(arguments.pSize, arguments.sSize, arguments.P)
