from pytest import raises
from src.args import parse_args, Arguments
from typing import List


def test_parser_invalid_numbers() -> None:
    args: List[str] = ["10"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_invalid_type() -> None:
    args: List[str] = ["a", "10"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_invalid_qi_value() -> None:
    args: List[str] = ["10", "10", "230"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_invalid_qi1_sup_qi2() -> None:
    args: List[str] = ["12", "10", "140", "100"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_valid_numbers() -> None:
    args: List[str] = ["10", "23"]
    expected: Arguments = Arguments(10, 23, None, None)
    assert expected == parse_args(args)


def test_parser_valid_qi1() -> None:
    args: List[str] = ["10", "23", "100"]
    expected: Arguments = Arguments(10, 23, 100, None)
    assert expected == parse_args(args)


def test_parser_valid_qi2() -> None:
    args: List[str] = ["10", "23", "100", "123"]
    expected: Arguments = Arguments(10, 23, 100, 123)
    assert expected == parse_args(args)


def test_parser_negative_mean() -> None:
    args: List[str] = ["-10", "23", "100", "123"]
    with raises(SystemExit):
        parse_args(args)
