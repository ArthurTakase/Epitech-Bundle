from argparse import ArgumentParser, ArgumentTypeError
from sys import argv
from typing import List, NamedTuple, Union, Any
from src.tools import extract_keys

AVAILABLE_CODES = extract_keys("data/207demography_data.json")

CountryCode = str

Numeric = Union[float, int]


class LinearInfo(NamedTuple):
    m_x: Numeric
    m_y: Numeric
    m_sqr_x: Numeric
    m_x_y: Numeric


class Coefficient(NamedTuple):
    a: Numeric
    b: Numeric


class Fit(NamedTuple):
    info: LinearInfo
    coeff: Coefficient
    coeff_to_print: Coefficient
    pop_2050: Numeric
    rmsd: Numeric


def countryCode(code: str) -> CountryCode:
    if code not in AVAILABLE_CODES:
        raise ArgumentTypeError(f"{code} isn't valid code")
    return code


def parse_args(arguments: List[str] = argv[1:]) -> Any:
    parser = ArgumentParser(description="./207demography code [...]")
    parser.add_argument("code", type=countryCode, nargs="+", help="country code")

    try:
        args = parser.parse_args(arguments)
    except SystemExit:
        exit(84)

    return args.code
