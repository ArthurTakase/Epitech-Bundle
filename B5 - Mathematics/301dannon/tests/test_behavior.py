from typing import Any
from src.dannon import main
from src.args import Argument, Array


def test_example1(capsys: Any) -> None:
    args: Array = [3.3, 5, 9.89, -6]
    arguments = Argument(args)
    main(arguments)
    assert (
        capsys.readouterr().out
        == """4 elements
Selection sort: 6 comparisons
Insertion sort: 4 comparisons
Bubble sort: 6 comparisons
Quicksort: 4 comparisons
Merge sort: 5 comparisons\n"""
    )


def test_example2(capsys: Any) -> None:
    args: Array = [
        -564,
        1340,
        42,
        129,
        858,
        1491,
        1508,
        246,
        -1281,
        655,
        1506,
        306,
        290,
        -768,
        116,
        765,
        -48,
        -512,
        2598,
        42,
        2339,
    ]
    arguments = Argument(args)
    main(arguments)
    assert (
        capsys.readouterr().out
        == """21 elements
Selection sort: 210 comparisons
Insertion sort: 125 comparisons
Bubble sort: 210 comparisons
Quicksort: 80 comparisons
Merge sort: 67 comparisons\n"""
    )
