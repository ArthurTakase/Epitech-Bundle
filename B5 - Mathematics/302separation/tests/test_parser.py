from typing import List
from pytest import raises
from src.args import NamesList, parse_args, Arguments


def test_file_dont_exit() -> None:
    with raises(SystemExit):
        parse_args(["no file", "3"])


def test_no_argument() -> None:
    with raises(SystemExit):
        parse_args([""])


def test_too_much_argument() -> None:
    with raises(SystemExit):
        parse_args(["1", "2", "3", "4"])


def test_distance_negative() -> None:
    with raises(SystemExit):
        parse_args(["docs/example", "-3"])


def test_distance_text() -> None:
    with raises(SystemExit):
        parse_args(["docs/example", "lol"])


def test_first_option() -> None:
    args = parse_args(["docs/example", "3"])
    expected = Arguments("docs/example", 3)

    assert isinstance(args.option, int)
    assert args == expected


def test_second_option() -> None:
    args = parse_args(["docs/example", "Yvette Horner", "Barack Obama"])
    expected = Arguments("docs/example", ["Yvette Horner", "Barack Obama"])

    assert isinstance(args.option, List)
    assert args == expected
