from pytest import raises
from src.compute import (
    temperature_increase_average,
    relative_temperature_evolution,
    standard_deviation,
    alert,
)
from typing import Any
from src.compute import temperatures


def test_compute1() -> None:
    period = 7

    temperatures.clear()

    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)
    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)

    assert temperature_increase_average(period) == "0.52"


def test_compute2() -> None:
    period = 7

    temperatures.clear()

    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)
    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)

    assert relative_temperature_evolution(period) == 0


def test_compute3() -> None:
    period = 7

    temperatures.clear()

    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)
    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)

    assert standard_deviation(period) == "0.75"


def test_compute4() -> None:
    period = 7
    nbSwitch = 0

    temperatures.clear()

    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)
    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)

    assert alert(period, nbSwitch) == ["", 0]
