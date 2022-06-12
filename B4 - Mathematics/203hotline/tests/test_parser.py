from pytest import raises
from src.args import Argument, parse_args, Binomial, CallDuration


def test_parser_invalid_binomial_type() -> None:
    with raises(SystemExit):
        parse_args(["100", "A"])


def test_parser_invalid_binomial_k_gt_n() -> None:
    with raises(SystemExit):
        parse_args(["100", "180"])


def test_parser_invalid_duration_type() -> None:
    with raises(SystemExit):
        parse_args(["A"])


def test_parser_no_argument() -> None:
    with raises(SystemExit):
        parse_args()


def test_parser_valid_duration() -> None:
    args: Argument = parse_args(["180"])
    if isinstance(args.args, Binomial):
        assert False
    assert args.args == 180


def test_parser_valid_binomial() -> None:
    args: Argument = parse_args(["100", "80"])
    if isinstance(args.args, CallDuration):
        assert False
    assert args.args == Binomial(100, 80)
