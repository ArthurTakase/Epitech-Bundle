from typing import Any
from src.args import Arguments

from src.pollution import main


def test_exampl1(capsys: Any) -> None:
    args = Arguments(3, "file.csv", 0.8, 0.8)
    main(args)
    assert capsys.readouterr().out == "26.11\n"


def test_exampl2(capsys: Any) -> None:
    args = Arguments(3, "file.csv", 0, 2)
    main(args)
    assert capsys.readouterr().out == "0.00\n"


def test_exampl3(capsys: Any) -> None:
    args = Arguments(3, "file.csv", 0.6, 2)
    main(args)
    assert capsys.readouterr().out == "28.20\n"


def test_exampl4(capsys: Any) -> None:
    args = Arguments(3, "file.csv", 1.3, 2)
    main(args)
    assert capsys.readouterr().out == "56.55\n"


def test_exampl5(capsys: Any) -> None:
    args = Arguments(3, "file.csv", 1, 1.5)
    main(args)
    assert capsys.readouterr().out == "33.94\n"
