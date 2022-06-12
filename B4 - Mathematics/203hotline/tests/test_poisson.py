from src.poisson import poisson


def test_poisson_3_lambda() -> None:
    _lambda: float = 21.875
    assert poisson(3, _lambda) == 5.514436537829572e-07


def test_poisson_40_lambda() -> None:
    _lambda: float = 21.875
    assert poisson(40, _lambda) == +0.00015349195158076399
