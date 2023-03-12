from pytest import raises
from src.args import Arguments, parse_args


def test_parser_valid_argument() -> None:
    args = ["3", "file.csv", "0.8", "0.8"]
    expected = Arguments(3, "file.csv", 0.8, 0.8)
    print(expected)

    assert parse_args(args) == expected


def test_parser_file_doesnt_exist() -> None:
    args = ["3", "nothing.csv", "0.8", "0.8"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_file_not_a_csv() -> None:
    args = ["3", "file.txt", "0.8", "0.8"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_bad_type_for_n() -> None:
    args = ["A", "file.csv", "0.8", "0.8"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_negative_n() -> None:
    args = ["-10", "file.csv", "0.8", "0.8"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_bad_type_for_x() -> None:
    args = ["3", "file.csv", "a", "0.8"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_negative_x() -> None:
    args = ["3", "file.csv", "-1", "0.8"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_bad_type_for_y() -> None:
    args = ["3", "file.csv", "0.8", "a"]
    with raises(SystemExit):
        parse_args(args)


def test_parser_negative_y() -> None:
    args = ["3", "file.csv", "0.8", "-1"]
    with raises(SystemExit):
        parse_args(args)
