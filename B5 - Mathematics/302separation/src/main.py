from src.args import Arguments, parse_args
from src.separation import Separation
from src.printSep import PrintSep


def main(args: Arguments) -> int:
    sep = Separation(args.file_name)
    sep.createGraph()
    sep.createDeepGraph()

    pri = PrintSep()
    if isinstance(args.option, int):
        pri.printNames(sep.names)
        pri.printGraph(sep.relationships)
        pri.printDeepGraph(sep.deep, args.option)
    else:
        pri.printSepBetween(
            args.option[0],
            args.option[1],
            sep.sepBetween(args.option[0], args.option[1]),
        )

    return 0
