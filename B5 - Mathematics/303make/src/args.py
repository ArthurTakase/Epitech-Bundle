from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import Any, List, NamedTuple, Union, Dict


class ParserReturn(NamedTuple):
    graph: Dict
    deep: Dict
    content: Dict


class Argument(NamedTuple):
    makefile: str
    file: Union[str, None]


def valid_file(string: str) -> str:
    try:
        with open(string) as file:
            return string
    except FileNotFoundError:
        raise ArgumentTypeError(f"file #{string} doesn't exist")


def parse_args(args: List[str] = argv[1:]) -> Any:
    parser = ArgumentParser()
    parser.add_argument("makefile", type=valid_file, help="name of the Makefile")
    parser.add_argument("file", nargs="?", type=str, help="name of the modified file")

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)
    return Argument(arguments.makefile, arguments.file)
