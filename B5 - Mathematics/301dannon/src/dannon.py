from src.args import Argument
from src.sort import Sort


def main(args: Argument) -> int:
    sorter = Sort(args.list)
    sorter.sort()
    print(sorter)
    return 0
