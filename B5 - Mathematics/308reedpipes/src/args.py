from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List, NamedTuple


class Argument(NamedTuple):
    r0: int
    r5: int
    r10: int
    r15: int
    r20: int
    n: int


def positive_float(string: str) -> float:
    number: float = 0
    try:
        number = float(string)
    except ValueError:
        ArgumentTypeError(f"{string} isn't an float")
    if number < 0:
        ArgumentTypeError(f"{string} isn't a positive float")
    return number


def positive_int(string: str) -> int:
    number: int = 0
    try:
        number = int(string)
    except ValueError:
        ArgumentTypeError(f"{string} isn't an integeer")
    if number < 0:
        ArgumentTypeError(f"{string} isn't a positive integeer")
    return number


def parser(args: List[str] = argv[1:]) -> Argument:
    parser = ArgumentParser()
    parser.add_argument(
        "r0", type=positive_float, help="radius (in cm) of pipa at the 0cm abscissa"
    )
    parser.add_argument(
        "r5", type=positive_float, help="radius (in cm) of pipa at the 5cm abscissa"
    )
    parser.add_argument(
        "r10", type=positive_float, help="radius (in cm) of pipa at the 10cm abscissa"
    )
    parser.add_argument(
        "r15", type=positive_float, help="radius (in cm) of pipa at the 15cm abscissa"
    )
    parser.add_argument(
        "r20", type=positive_float, help="radius (in cm) of pipa at the 20cm abscissa"
    )
    parser.add_argument(
        "n", type=positive_int, help="number of points to display the radius"
    )

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)
    return Argument(
        arguments.r0,
        arguments.r5,
        arguments.r10,
        arguments.r15,
        arguments.r20,
        arguments.n,
    )
