from pytest import raises
from src.neutrinos import display
from typing import Any
from src.args import Neutrino
from src.compute import compute_values


def test_display(capsys: Any) -> None:
    values: Neutrino = Neutrino(12000, 297514, 297912, 4363)
    compute_values(values, 299042.0)
    display(values)
    assert (
        capsys.readouterr().out
        == "\tNumber of values:\t12001\n\tStandard deviation:\t4362.84\n\tArithmetic mean:\t297514.13\n\tRoot mean square:\t297546.11\n\tHarmonic mean:\t\t297912.09\n\n"
    )
