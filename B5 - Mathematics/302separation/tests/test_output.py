from typing import Any
from src.args import parse_args
from src.main import main


def test_example(capsys: Any) -> None:
    args = parse_args(["docs/example", "3"])
    main(args)

    assert (
        capsys.readouterr().out
        == "Barack Obama\nChuck Norris\nCindy Crawford\nFrançois Hollande\nJesus\nKatie Holmes\nLara Croft\nNicole Kidman\nPenelope Cruiz\nSim\nTom Cruise\nV\nYvette Horner\n\n0 1 0 1 0 0 0 0 0 0 1 1 0\n1 0 0 0 1 0 0 0 0 1 0 0 0\n0 0 0 0 0 0 0 1 0 0 0 0 0\n1 0 0 0 0 0 0 0 0 0 0 1 0\n0 1 0 0 0 0 0 0 0 1 0 0 0\n0 0 0 0 0 0 0 0 0 0 1 0 0\n0 0 0 0 0 0 0 0 0 1 0 1 0\n0 0 1 0 0 0 0 0 0 0 1 0 0\n0 0 0 0 0 0 0 0 0 0 1 0 0\n0 1 0 0 1 0 1 0 0 0 0 0 1\n1 0 0 0 0 1 0 1 1 0 0 0 0\n1 0 0 1 0 0 1 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 1 0 0 0\n\n0 1 3 1 2 2 2 2 2 2 1 1 3\n1 0 0 2 1 3 2 3 3 1 2 2 2\n3 0 0 0 0 3 0 1 3 0 2 0 0\n1 2 0 0 3 3 2 3 3 3 2 1 0\n2 1 0 3 0 0 2 0 0 1 3 3 2\n2 3 3 3 0 0 0 2 2 0 1 3 0\n2 2 0 2 2 0 0 0 0 1 3 1 2\n2 3 1 3 0 2 0 0 2 0 1 3 0\n2 3 3 3 0 2 0 2 0 0 1 3 0\n2 1 0 3 1 0 1 0 0 0 3 2 1\n1 2 2 2 3 1 3 1 1 3 0 2 0\n1 2 0 1 3 3 1 3 3 2 2 0 3\n3 2 0 0 2 0 2 0 0 1 0 3 0\n"
    )


def test_example1(capsys: Any) -> None:
    args = parse_args(["docs/example", "Yvette Horner", "Barack Obama"])
    main(args)

    assert (
        capsys.readouterr().out
        == "Degree of separation between Yvette Horner and Barack Obama: 3\n"
    )


def test_example2(capsys: Any) -> None:
    args = parse_args(["docs/example", "Yvette Horner", "Yvette Horner"])
    main(args)

    assert (
        capsys.readouterr().out
        == "Degree of separation between Yvette Horner and Yvette Horner: 0\n"
    )


def test_example3(capsys: Any) -> None:
    args = parse_args(["docs/example", "Yvette Horner", "Mike Tyson"])
    main(args)

    assert (
        capsys.readouterr().out
        == "Degree of separation between Yvette Horner and Mike Tyson: -1\n"
    )
