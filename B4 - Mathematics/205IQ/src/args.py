from argparse import ArgumentParser, ArgumentTypeError
from typing import NamedTuple, Union
from sys import argv
from typing import List


class Arguments(NamedTuple):
    u: int
    s: int
    IQ1: Union[None, int]
    IQ2: Union[None, int]


def mean(string: str) -> int:
    try:
        nb: int = int(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't an integer")
    if nb < 0 or nb > 200:
        raise ArgumentTypeError(f"{string} isn't valid mean")
    return nb


def positive_int(string: str) -> int:
    try:
        nb: int = int(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't an integer")
    if nb < 0:
        raise ArgumentTypeError(f"{string} isn't positive integer")
    return nb


def qi(string: str) -> int:
    try:
        nb: int = int(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't an integer")
    if nb < 0 or nb > 200:
        raise ArgumentTypeError(f"{string} invalid qi")
    return nb


def parse_args(arguments: List[str] = argv[1:]) -> Arguments:
    parser = ArgumentParser(description="./205IQ u s [IQ1] [IQ2]")
    parser.add_argument("u", type=mean, help="mean")
    parser.add_argument("s", type=positive_int, help="standard deviation")

    parser.add_argument("IQ1", type=qi, nargs="?", help="minimum IQ")
    parser.add_argument("IQ2", type=qi, nargs="?", help="maximum IQ")

    try:
        args = parser.parse_args(arguments)
    except SystemExit:
        exit(84)
    if args.IQ1 and args.IQ2 and args.IQ1 > args.IQ2:
        print("IQ1 must be inferior to IQ2")
        exit(84)
    return Arguments(args.u, args.s, args.IQ1, args.IQ2)
