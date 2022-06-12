from src.binomial import binomial, binomial_int, fact


def test_fact_10() -> None:
    assert fact(10) == 3628800


def test_binomial_int_100_18() -> None:
    assert binomial_int(100, 18) == 30664510802988208300


def test_binomial_3500_3() -> None:
    assert binomial(3500, 3) == +7139709500.0


def test_binomial_3500_41() -> None:
    assert binomial(3500, 41) == +4.788694746404062e95
