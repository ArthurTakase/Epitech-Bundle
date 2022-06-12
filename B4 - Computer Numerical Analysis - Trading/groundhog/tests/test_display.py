from pytest import raises
from src.ground import display_results
from typing import Any
from src.compute import temperatures


def test_display1(capsys: Any) -> None:
    period = 7
    convert_buffer = 27.7
    nbSwitch = 0

    temperatures.clear()

    display_results(period, convert_buffer, nbSwitch)

    assert capsys.readouterr().out == "g=nan\t\tr=nan%\t\ts=nan\n"


def test_display2(capsys: Any) -> None:
    period = 7
    convert_buffer = 27.7
    nbSwitch = 0

    temperatures.clear()

    temperatures.append(90.70)
    temperatures.append(92.90)
    temperatures.append(92.98)
    temperatures.append(91.80)
    temperatures.append(92.66)
    temperatures.append(92.30)
    temperatures.append(92.77)

    display_results(period, convert_buffer, nbSwitch)

    assert capsys.readouterr().out == "g=nan\t\tr=nan%\t\ts=0.75\n"


def test_display3(capsys: Any) -> None:
    period = 7
    convert_buffer = 27.7
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

    display_results(period, convert_buffer, nbSwitch)

    assert capsys.readouterr().out == "g=0.52\t\tr=0%\t\ts=0.75\n"
