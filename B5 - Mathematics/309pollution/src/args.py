from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List, NamedTuple

Number = int | float


class Arguments(NamedTuple):
    n: int
    file_name: str
    x: Number
    y: Number


def positive_int(string: str) -> int:
    try:
        number: int = int(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't a number")
    if number < 0:
        raise ArgumentTypeError(f"{string} isn't positive")
    return number


def positive_float(string: str) -> float:
    try:
        number: float = float(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't a number")
    if number < 0:
        raise ArgumentTypeError(f"{string} isn't positive")
    return number


def csv_file(string: str) -> str:
    if not string.endswith(".csv"):
        raise ArgumentTypeError(f"{string} isn't a csv file")
    try:
        with open(string) as _:
            return string
    except FileNotFoundError:
        raise ArgumentTypeError(f"{string} is not a file")


def parse_args(arguments: List[str] = argv[1:]) -> Arguments:
    parser = ArgumentParser()
    parser.add_argument("n", type=positive_int, help="number of points on the grid axis")
    parser.add_argument("file", type=csv_file, help="csv file containing the data points x;y;p")
    parser.add_argument(
        "x",
        type=positive_float,
        help="abscissa of the point whose pollution level we want to know",
    )
    parser.add_argument(
        "y",
        type=positive_float,
        help="ordinate of the point whose pollution level we want to know",
    )

    try:
        args = parser.parse_args(arguments)
    except SystemExit:
        exit(84)
    return Arguments(n=args.n, file_name=args.file, x=args.x, y=args.y)
