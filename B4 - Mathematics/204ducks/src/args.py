from argparse import ArgumentTypeError, ArgumentParser
from sys import argv
from typing import List, Any, NamedTuple


class DuckInfo(NamedTuple):
    average: str
    standard_deviation: float
    back_50: float
    back_99: float
    back_1_min: float
    back_2_min: float


def real_constant(string: str) -> float:
    try:
        nb: float = float(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't a number")
    if nb < 0.0 or nb > 2.5:
        raise ArgumentTypeError(f"{string} must be between 0.0 and 2.5")
    return nb


def parse_args(args: List[str] = argv[1:]) -> Any:
    parser = ArgumentParser()
    parser.add_argument("a", type=real_constant, help="constant")

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)
    return arguments.a
