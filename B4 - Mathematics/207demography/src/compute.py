from typing import List, Union, Any
from src.args import LinearInfo, Coefficient, Fit, Numeric
from src.tools import to_int_array
from math import sqrt


def get_fit(years: List[Any], population: List[Any], fit1: bool) -> Fit:
    info: LinearInfo = get_linear_info(years, population)
    coeff: Coefficient = get_coefficient(info)
    coeff_to_print: Coefficient = get_coefficient_to_print(coeff.a, coeff.b, fit1)
    pop_2050: Numeric = get_pop_2050(coeff, fit1)
    rmsd: Numeric = RMSD(coeff, population, years, fit1)
    return Fit(info, coeff, coeff_to_print, pop_2050, rmsd)


def get_linear_info(str_years: List[Any], population: List[Any]) -> LinearInfo:
    years: List[int] = to_int_array(str_years)
    population = to_int_array(population)
    m_x: Numeric = sum(years) / len(years)
    m_y: Numeric = sum(population) / len(population)
    m_sqr_x: Numeric = sum([year**2 for year in years]) / len(years)
    m_x_y: Numeric = sum(x * y for x, y in zip(years, population)) / len(years)
    info: LinearInfo = LinearInfo(m_x, m_y, m_sqr_x, m_x_y)
    return info


def get_coefficient(info: LinearInfo) -> Coefficient:
    a: Numeric = (info.m_x_y - (info.m_x * info.m_y)) / (info.m_sqr_x - (info.m_x**2))
    b: Numeric = info.m_y - (a * info.m_x)
    coeff: Coefficient = Coefficient(a, b)
    return coeff


def get_coefficient_to_print(a: Numeric, b: Numeric, fit1: bool) -> Coefficient:
    coeff: Coefficient = (
        Coefficient(a / 1000000, b / 1000000) if fit1 else Coefficient(a * 1000000, b)
    )
    return coeff


def get_pop_2050(coeff: Coefficient, fit1: bool) -> Numeric:
    if fit1:
        return (coeff.a * 2050 + coeff.b) / 1000000
    return ((2050 - coeff.b) / coeff.a) / 1000000


def RMSD(
    coeff: Coefficient, y_values: List[Numeric], years: List[Numeric], fit1: bool
) -> Numeric:
    sum_res: Numeric = (
        sum_residual(coeff.a, coeff.b, y_values, years, fit1)
        if fit1
        else sum_residual(coeff.a, coeff.b, years, y_values, fit1)
    )
    res: Numeric = sqrt(sum_res / (len(years)))
    return res


def sum_residual(
    a: Numeric, b: Numeric, y_values: List[Numeric], years: List[Numeric], fit1: bool
) -> Numeric:
    sum_res: Numeric = 0.0
    for x, y in zip(years, y_values):
        y_expected: Numeric = (
            (a * int(x) + b) / 1000000 if fit1 else ((int(x) - b) / a) / 1000000
        )
        y_current: Numeric = int(y) / 1000000
        sum_res += (y_current - y_expected) ** 2

    return sum_res


def get_correlation(
    info: LinearInfo, years: List[Union[str, int]], populations: List[Union[str, int]]
) -> float:

    dividente: Numeric = get_correlation_dividente(info, years, populations)
    diviseur: Numeric = get_correlation_diviseur(info, years, populations)
    res: Numeric = dividente / sqrt(diviseur)
    return res


def get_correlation_dividente(
    info: LinearInfo, years: List[Union[str, int]], populations: List[Union[str, int]]
) -> float:
    res: Numeric = 0.0
    for x, y in zip(years, populations):
        res += (float(x) - info.m_x) * (float(y) - info.m_y)
    return res


def get_correlation_diviseur(
    info: LinearInfo, years: List[Union[str, int]], populations: List[Union[str, int]]
) -> float:
    X: Numeric = sum([(float(x) - info.m_x) ** 2 for x in years])
    Y: Numeric = sum([(float(y) - info.m_y) ** 2 for y in populations])
    return X * Y
