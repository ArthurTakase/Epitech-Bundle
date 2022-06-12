from argparse import ArgumentTypeError, ArgumentParser
from sys import argv
from typing import List, NamedTuple, Union


class Binomial(NamedTuple):
    n: int
    k: int


class ResultDistribution(NamedTuple):
    overload: float
    time: float
    distribution: List[float]


CallDuration = float


class Argument(NamedTuple):
    args: Union[Binomial, CallDuration]


def positive_int(string: str) -> int:
    try:
        value: int = int(string)
    except:
        raise ArgumentTypeError(f"{string} isn't a number")
    if value < 0:
        raise ArgumentTypeError(f"{string} isn't positive")
    return value


def positive_float(string: str) -> float:
    try:
        value: float = float(string)
    except:
        raise ArgumentTypeError(f"{string} isn't a number")
    if value < 0:
        raise ArgumentTypeError(f"{string} isn't positive")
    return value


def parse_args(args: List[str] = argv[1:]) -> Argument:
    parser = ArgumentParser()
    parser.add_argument(
        "--binomial",
        nargs=2,
        type=positive_int,
        help="n value for the computation of C(n, k",
    )
    parser.add_argument(
        "--duration",
        type=positive_float,
        help="d average duration of calls (in seconds",
    )

    if len(args) == 2:
        args.insert(0, "--binomial")
    else:
        args.insert(0, "--duration")

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)

    if not arguments.binomial is None:
        binomial: Binomial = Binomial(arguments.binomial[0], arguments.binomial[1])
        if binomial.k > binomial.n:
            print("Error n must be geater or equal to k")
            exit(84)
        return Argument(binomial)
    if not arguments.duration is None:
        duration: CallDuration = CallDuration(arguments.duration)
        return Argument(duration)
    exit(84)
