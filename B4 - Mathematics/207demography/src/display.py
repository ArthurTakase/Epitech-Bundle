from src.args import LinearInfo, Coefficient, Fit, CountryCode, Numeric
from typing import List


def display_result(
    fit1: Fit, fit2: Fit, countries_name: List[str], correlation: Numeric
) -> None:
    print("Country:", end="")
    for country_name in countries_name:
        print(f" {country_name}", end="")
    display_fit1(fit1)
    display_fit2(fit2)
    print(f"Correlation: {correlation:.4f}")


def display_fit1(fit: Fit) -> None:
    print(f"\nFit1")
    print(
        f"\tY = {fit.coeff_to_print.a:.2f} X {'-' if fit.coeff_to_print.b < 0 else '+'} {abs(fit.coeff_to_print.b):.2f}"
    )
    print(f"\tRoot-mean-square deviation: {fit.rmsd:.2f}")
    print(f"\tPopulation in 2050: {fit.pop_2050:.2f}")


def display_fit2(fit: Fit) -> None:
    print(f"Fit2")
    print(
        f"\tX = {fit.coeff_to_print.a:.2f} Y {'-' if fit.coeff_to_print.b < 0 else '+'} {abs(fit.coeff_to_print.b):.2f}"
    )
    print(f"\tRoot-mean-square deviation: {fit.rmsd:.2f}")
    print(f"\tPopulation in 2050: {fit.pop_2050:.2f}")
