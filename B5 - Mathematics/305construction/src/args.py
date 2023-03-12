from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import Any, List, NamedTuple
from src.task import Task

class Argument(NamedTuple):
    tasks: List[Task]

def valid_file(string: str) -> str:
    try:
        with open(string) as _:
            return string
    except FileNotFoundError:
        raise ArgumentTypeError(f"file #{string} doesn't exist")


def parse_args(args: List[str] = argv[1:]) -> Any:
    parser = ArgumentParser()
    parser.add_argument("file", type=valid_file, help="file describing the tasks")

    try:
        arguments = parser.parse_args(args)
    except SystemExit:
        exit(84)

    with open(arguments.file) as file:
        tasks = {}
        for line in file.readlines():
            task = Task(line.rstrip())
            tasks[task.id] = task

    return Argument(tasks)