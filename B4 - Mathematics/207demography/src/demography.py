from src.tools import load_json
from src.args import Fit, CountryCode, Numeric
from src.compute import get_correlation, get_fit
from src.display import display_result
from typing import List, Dict, Iterator, Any, Union


DATA: Dict[Any, Any] = load_json("data/207demography_data.json")
ACTUAL_DATA: List[Dict[Any, Any]] = []
ACTUAL_COUNTRY_NAME: List[str] = []


def all_years(code: CountryCode) -> Iterator[str]:
    for value in DATA[code]:
        try:
            int(value)
        except ValueError:
            continue
        yield (str(value))


def get_pop_by_years(codes: List[CountryCode]) -> Dict[str, int]:
    years: Dict[str, int] = dict()
    for year in all_years(codes[0]):
        years[year] = 0
        for code in codes:
            years[year] += int(DATA[code][year])
    return years


def demography(country_codes: List[CountryCode]) -> None:
    all_pop_by_year: Dict[str, int] = get_pop_by_years(country_codes)
    countries_name: List[str] = [DATA[code]["Country Name"] for code in country_codes]
    all_years: List[Union[int, str]] = list(all_pop_by_year.keys())
    all_pop: List[Union[int, str]] = list(all_pop_by_year.values())
    fit1: Fit = get_fit(all_years, all_pop, True)
    fit2: Fit = get_fit(all_pop, all_years, False)
    correlation: Numeric = get_correlation(fit1.info, all_years, all_pop)
    display_result(fit1, fit2, countries_name, correlation)
