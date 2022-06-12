from pytest import raises
from typing import Any
from src.ducks import main


def test_example_1(capsys: Any) -> None:
    main(1.6)
    assert (
        capsys.readouterr().out
        == "Average return time: 1m 21s\nStandard deviation: 1.074\nTime after which 50% of the ducks are back: 1m 04s\nTime after which 99% of the ducks are back: 5m 04s\nPercentage of ducks back after 1 minute: 46.9%\nPercentage of ducks back after 2 minutes: 79.1%\n"
    )


def test_example_2(capsys: Any) -> None:
    main(0.2)
    assert (
        capsys.readouterr().out
        == "Average return time: 0m 50s\nStandard deviation: 0.676\nTime after which 50% of the ducks are back: 0m 39s\nTime after which 99% of the ducks are back: 3m 16s\nPercentage of ducks back after 1 minute: 71.3%\nPercentage of ducks back after 2 minutes: 94.2%\n"
    )
