from argparse import ArgumentParser, ArgumentTypeError
from typing import Any, List, NamedTuple, Union
from sys import argv

NamesList = List[str]


class Arguments(NamedTuple):
    file_name: str
    option: Union[int, NamesList]


def positive_int(string: str) -> int:
    try:
        number: int = int(string)
    except ValueError:
        raise ArgumentTypeError(f"{string} isn't a number")
    if number < 0:
        raise ArgumentTypeError(f"{string} isn't positive")
    return number


def file_valid(name: str) -> str:
    try:
        with open(name) as file:
            return name
    except FileNotFoundError:
        raise ArgumentTypeError(f"{name} file doesn't exist")


def parse_args(args: List[str] = argv[1:]) -> Any:
    parser = ArgumentParser()
    parser.add_argument(
        "file", type=file_valid, help="File containing all the relations"
    )
    parser.add_argument(
        "--distance_max", type=positive_int, help="distance max between two people"
    )
    parser.add_argument(
        "--names", nargs=2, type=str, help="distance max between two people"
    )

    try:
        if len(args) == 2:
            args.insert(1, "--distance_max")
        elif len(args) == 3:
            args.insert(1, "--names")
        else:
            raise ArgumentTypeError("Number of argument isn't valid")
        arguments = parser.parse_args(args)
    except:
        exit(84)
    if not arguments.distance_max is None:
        return Arguments(arguments.file, arguments.distance_max)
    return Arguments(arguments.file, arguments.names)
