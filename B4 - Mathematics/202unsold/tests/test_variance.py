from typing import Any
from src.variance import calcul_variance
from src.args import Variance
from src.display import display_variance


def test_calcul_variance() -> None:
    res: Variance = calcul_variance(
        [0.33, 0.27, 0.20, 0.13, 0.07], [0.3, 0.25, 0.2, 0.15, 0.1]
    )
    assert res == Variance(
        totalX=23.400000000000002, totalY=25.0, expX=156.44000000000003, expY=175.0
    )


def test_display_variance(capsys: Any) -> None:
    variance: Variance = calcul_variance(
        [0.33, 0.27, 0.20, 0.13, 0.07], [0.3, 0.25, 0.2, 0.15, 0.1]
    )
    display_variance(variance)
    assert (
        capsys.readouterr().out
        == "expected value of X:\t25.0\nvariance of X:\t\t175.0\nexpected value of Y:\t23.4\nvariance of Y:\t\t156.4\nexpected value of Z:\t48.4\nvariance of Z:\t\t331.4\n"
    )
