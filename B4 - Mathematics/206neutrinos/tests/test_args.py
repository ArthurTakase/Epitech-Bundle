from pytest import raises
from typing import List
from src.args import parse_args, Arguments


def test_parser_valid() -> None:
    args: List[str] = ["1200", "29715", "29876", "4363"]
    current: Arguments = parse_args(args)
    expected: Arguments = Arguments(1200, 29715, 29876, 4363)
    assert current == expected


def test_parser_invalid_type() -> None:
    args: List[str] = ["dsqf", "29715", "29876", "4363"]
    with raises(SystemExit):
        parse_args()


def test_parser_not_enought_arg() -> None:
    args: List[str] = ["29715", "29876", "4363"]
    with raises(SystemExit):
        parse_args()


def test_parser_too_many_arg() -> None:
    args: List[str] = ["1200", "29715", "29876", "4363", "69097"]
    with raises(SystemExit):
        parse_args()
