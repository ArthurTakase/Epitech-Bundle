from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List

class Parser:
    def __init__(self):
        self.args = self.parse_args()

    def positive_int(self, string: str) -> int:
        try: number: int = int(string)
        except ValueError: raise (ArgumentTypeError(f"{string} isn't a valid integer"))
        if number < 0: raise (ArgumentTypeError(f"{string} is negative"))
        return number

    def parse_args(self, args: List[str] = argv[1:]):
        parser = ArgumentParser("307-multigrains")
        parser.add_argument("n1", type=self.positive_int, help="number of tons of fertilizer F1")
        parser.add_argument("n2", type=self.positive_int, help="number of tons of fertilizer F2")
        parser.add_argument("n3", type=self.positive_int, help="number of tons of fertilizer F3")
        parser.add_argument("n4", type=self.positive_int, help="number of tons of fertilizer F4")
        parser.add_argument("po", type=self.positive_int, help="price of one unit of oat")
        parser.add_argument("pw", type=self.positive_int, help="price of one unit of wheat")
        parser.add_argument("pc", type=self.positive_int, help="price of one unit of corn")
        parser.add_argument("pb", type=self.positive_int, help="price of one unit of barley")
        parser.add_argument("ps", type=self.positive_int, help="price of one unit of soy")

        try: args = parser.parse_args(args)
        except SystemExit: exit(84)

        return [args.n1, args.n2, args.n3, args.n4, args.po, args.pw, args.pc, args.pb, args.ps]