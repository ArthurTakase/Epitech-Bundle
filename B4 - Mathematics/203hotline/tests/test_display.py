from src.args import ResultDistribution
from src.display import display_binomial, display_distribution
from src.duration import binomial_distribution, poisson_distribution
from typing import Any


def test_display_binomial(capsys: Any) -> None:
    display_binomial(100, 18, 30664510802988208300)
    assert (
        capsys.readouterr().out
        == "18-combinations of a set of size 100:\n30664510802988208300\n"
    )


def test_display_distribution_binomial(capsys: Any) -> None:
    res: ResultDistribution = binomial_distribution(180)
    display_distribution(res)
    assert capsys.readouterr().out.startswith(
        "0 -> 0.000\t1 -> 0.000\t2 -> 0.000\t3 -> 0.000\t4 -> 0.000\n5 -> 0.000\t6 -> 0.000\t7 -> 0.000\t8 -> 0.000\t9 -> 0.001\n10 -> 0.002\t11 -> 0.004\t12 -> 0.008\t13 -> 0.013\t14 -> 0.021\n15 -> 0.030\t16 -> 0.041\t17 -> 0.053\t18 -> 0.065\t19 -> 0.075\n20 -> 0.082\t21 -> 0.085\t22 -> 0.085\t23 -> 0.081\t24 -> 0.074\n25 -> 0.064\t26 -> 0.054\t27 -> 0.044\t28 -> 0.034\t29 -> 0.026\n30 -> 0.019\t31 -> 0.013\t32 -> 0.009\t33 -> 0.006\t34 -> 0.004\n35 -> 0.002\t36 -> 0.001\t37 -> 0.001\t38 -> 0.000\t39 -> 0.000\n40 -> 0.000\t41 -> 0.000\t42 -> 0.000\t43 -> 0.000\t44 -> 0.000\n45 -> 0.000\t46 -> 0.000\t47 -> 0.000\t48 -> 0.000\t49 -> 0.000\n50 -> 0.000\nOverload: 21.4%\nComputation time:"
    )


def test_display_distribution_duration(capsys: Any) -> None:
    res: ResultDistribution = poisson_distribution(180)
    display_distribution(res)
    assert capsys.readouterr().out.startswith(
        "0 -> 0.000\t1 -> 0.000\t2 -> 0.000\t3 -> 0.000\t4 -> 0.000\n5 -> 0.000\t6 -> 0.000\t7 -> 0.000\t8 -> 0.000\t9 -> 0.001\n10 -> 0.002\t11 -> 0.004\t12 -> 0.008\t13 -> 0.013\t14 -> 0.021\n15 -> 0.030\t16 -> 0.042\t17 -> 0.053\t18 -> 0.065\t19 -> 0.075\n20 -> 0.082\t21 -> 0.085\t22 -> 0.085\t23 -> 0.081\t24 -> 0.073\n25 -> 0.064\t26 -> 0.054\t27 -> 0.044\t28 -> 0.034\t29 -> 0.026\n30 -> 0.019\t31 -> 0.013\t32 -> 0.009\t33 -> 0.006\t34 -> 0.004\n35 -> 0.002\t36 -> 0.001\t37 -> 0.001\t38 -> 0.001\t39 -> 0.000\n40 -> 0.000\t41 -> 0.000\t42 -> 0.000\t43 -> 0.000\t44 -> 0.000\n45 -> 0.000\t46 -> 0.000\t47 -> 0.000\t48 -> 0.000\t49 -> 0.000\n50 -> 0.000\nOverload: 21.5%\nComputation time:"
    )
