from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List


def positive_int(string: str) -> int:
    try:
        number: int = int(string)
    except ValueError:
        raise (ArgumentTypeError(f"{string} isn't a valid integer"))
    if number < 0:
        raise (ArgumentTypeError(f"{string} is negative"))
    return number


def parse_args(args: List[str] = argv[1:]):
    parser = ArgumentParser("306-Radiator")
    parser.add_argument("size", type=positive_int, help="size of the room")
    parser.add_argument("ir", type=positive_int, help="x coordinate for radiator")
    parser.add_argument("jr", type=positive_int, help="y coordinate for radiator")
    parser.add_argument("i", type=positive_int, nargs="?", help="x coordinate")
    parser.add_argument("j", type=positive_int, nargs="?", help="y coordinate")

    try:
        arguments = parser.parse_args(args)
        if arguments.i != None and arguments.j == None:
            print("j missing")
            exit(84)
    except SystemExit:
        exit(84)

    return arguments
