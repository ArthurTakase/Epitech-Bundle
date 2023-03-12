from pytest import raises
from src.args import Array, parse_args


def test_parser_valid() -> None:
    expected: Array = [3.3, 5, 9.89, -6]
    actual: Array = parse_args(["tests/list"]).list
    assert actual == expected


def test_parser_invalid_file() -> None:
    with raises(SystemExit):
        parse_args(["tests/list_invalid"])
