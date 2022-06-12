from pytest import raises
from src.args import parse_args
from typing import List


def test_parser_valid() -> None:
    expected: List[str] = ["EUU"]
    actual: List[str] = parse_args(["EUU"])
    assert actual == expected


def test_parser_invalid_code() -> None:
    with raises(SystemExit):
        parse_args(["AVSD"])


def test_parser_not_enought_arg() -> None:
    with raises(SystemExit):
        parse_args([])


def test_parer_valid_and_invalid_code() -> None:
    with raises(SystemExit):
        parse_args(["EUU", "ACSD"])
