from argparse import ArgumentParser, Namespace
from sys import argv
from typing import List, NamedTuple


class Neutrino:
    def __init__(self, n: float, a: float, h: float, sd: float):
        self.n: float = n
        self.a: float = a
        self.h: float = h
        self.sd: float = sd
        self.new_root: float = 0.0


class Arguments(NamedTuple):
    n: float
    a: float
    h: float
    sd: float


def parse_args(arguments: List[str] = argv[1:]) -> Arguments:
    parser = ArgumentParser(description="./206neutrinos n a h sd")
    parser.add_argument("n", type=float, help="number of values")
    parser.add_argument("a", type=float, help="aritmetic mean")
    parser.add_argument("h", type=float, help="harmonic mean")
    parser.add_argument("sd", type=float, help="standard deviation")

    try:
        args = parser.parse_args(arguments)
    except SystemExit:
        exit(84)

    return Arguments(args.n, args.a, args.h, args.sd)
