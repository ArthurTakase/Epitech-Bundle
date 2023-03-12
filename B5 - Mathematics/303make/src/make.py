from src.args import Argument, ParserReturn
from src.parser import parser, get_links
from src.print import print_result
from src.commands import searchCommands
from typing import List

def main(args: Argument) -> int:
    parser_return: ParserReturn = parser(args.makefile)
    file_links = get_links(parser_return.deep)

    if args.file:
        keys: List[str] = list(parser_return.graph.keys())
        return searchCommands(parser_return.content, keys, args.file)
    else:
        return print_result(parser_return.deep, file_links)
