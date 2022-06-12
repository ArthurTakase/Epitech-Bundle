from pytest import raises
from src.args import parse_args


def test_parser_invalid_type() -> None:
    with raises(SystemExit):
        parse_args(["a"])


def test_parser_too_big() -> None:
    with raises(SystemExit):
        parse_args(["2.9"])


def test_parser_too_small() -> None:
    with raises(SystemExit):
        parse_args(["-1.2"])


def test_parser_valid() -> None:
    args: float = parse_args(["1.3"])
    assert args == 1.3
