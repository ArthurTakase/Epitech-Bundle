from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List, NamedTuple


class Variance(NamedTuple):
    totalX: float
    totalY: float
    expX: float
    expY: float


class Laws(NamedTuple):
    x: List[float]
    y: List[float]


class Argument(NamedTuple):
    a: int
    b: int


def positive_int(string: str) -> int:
    try:
        value = int(string)
    except:
        raise ArgumentTypeError(f"'{string}' isn't an integer")
    if value < 50:
        raise ArgumentTypeError(f"'{string}' isn't correct")
    return value


def parse_args(arguments: List[str] = argv[1:]) -> Argument:
    parser = ArgumentParser()
    parser.add_argument(
        "a", type=positive_int, help="constant computed from past results"
    )
    parser.add_argument(
        "b", type=positive_int, help="constant computed from past results"
    )
    try:
        args = parser.parse_args(arguments)
    except SystemExit:
        exit(84)
    return Argument(args.a, args.b)
