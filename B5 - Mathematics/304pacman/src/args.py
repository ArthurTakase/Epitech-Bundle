from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import Any, List, NamedTuple

class Argument(NamedTuple):
    file: str
    c1: str
    c2: str

def valid_file(string: str) -> str:
    try:
        with open(string) as file:
            return string   
    except FileNotFoundError:
        raise ArgumentTypeError(f"file #{string} doesn't exist")


def parse_args(args: List[str] = argv[1:]) -> Any:
    parser = ArgumentParser()
    parser.add_argument("file", type=valid_file, help="""
    file describing the board, using the following characters:
'0' for an empty square,
'1' for a wall,
'F' for the ghost's position,
'P' for Pacman's position.""")
    parser.add_argument("c1", type=str, help="character to display for a wall")
    parser.add_argument("c2", type=str, help="character to display for an empty space.")

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)
    return Argument(arguments.file, arguments.c1, arguments.c2)