from pytest import raises
from src.args import Argument, parse_args


def test_parser_valid() -> None:
    args: Argument = parse_args(["60", "70"])
    assert args == Argument(a=60, b=70)


def test_parser_invalid_type() -> None:
    with raises(SystemExit):
        parse_args(["a", "60"])


def test_parser_invalid_value_less_than_50() -> None:
    with raises(SystemExit):
        parse_args(["40", "60"])


def test_parser_missing_value() -> None:
    with raises(SystemExit):
        parse_args(["60"])


def test_parser_too_much_value() -> None:
    with raises(SystemExit):
        parse_args(["60", "70", "80"])
