from argparse import ArgumentParser, Namespace, ArgumentTypeError
from sys import argv
from typing import List


def posInt(data: str) -> int:
    try:
        temp: int = int(data)
        if temp < 0:
            raise ArgumentTypeError(f"{data} must be positiv")
        return temp
    except:
        raise ArgumentTypeError(f"{data} is not a number")


def parse_args(arguments: List[str] = argv[1:]) -> List[int]:
    parser: ArgumentParser = ArgumentParser(
        description="./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8")
    parser.add_argument("O0", type=posInt, help="size of the observed class")
    parser.add_argument("O1", type=posInt, help="size of the observed class")
    parser.add_argument("O2", type=posInt, help="size of the observed class")
    parser.add_argument("O3", type=posInt, help="size of the observed class")
    parser.add_argument("O4", type=posInt, help="size of the observed class")
    parser.add_argument("O5", type=posInt, help="size of the observed class")
    parser.add_argument("O6", type=posInt, help="size of the observed class")
    parser.add_argument("O7", type=posInt, help="size of the observed class")
    parser.add_argument("O8", type=posInt, help="size of the observed class")

    try:
        args: Namespace = parser.parse_args(arguments)
    except SystemExit:
        exit(84)

    temp: List[int] = [args.O0, args.O1, args.O2, args.O3,
                       args.O4, args.O5, args.O6, args.O7, args.O8]

    if sum(temp) != 100:
        exit(84)

    return temp
