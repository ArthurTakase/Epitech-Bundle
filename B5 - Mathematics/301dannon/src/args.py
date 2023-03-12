from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List, NamedTuple, Union

Numeric = Union[float, int]

Array = List[Numeric]


class Argument(NamedTuple):
    list: Array


def file_list(string: str) -> List[Numeric]:
    result: List[Numeric] = []
    try:
        with open(string) as file_list:
            lines = file_list.read()
            elements = lines.split(" ")
            for element in elements:
                try:
                    number = float(element)
                    result.append(number)
                except ValueError:
                    raise ArgumentTypeError(f"{element} isn't a number")
        return result
    except:
        raise ArgumentTypeError(f"{string} is not a valid file")


def parse_args(args: List[str] = argv[1:]) -> Argument:
    parser = ArgumentParser()
    parser.add_argument(
        "List", type=file_list, help="A file which contains the list you which to test"
    )

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)
    return Argument(arguments.List)
