from src.utils import (
    esperance,
    variance,
    convert_time,
    duck_probability,
    timeForDuckToReturnPourcent,
)
from src.args import DuckInfo
from src.display import display_info


def get_info(constant: float) -> DuckInfo:
    average_return: float = convert_time(esperance(constant))
    standard_deviation: float = variance(constant)
    back_50: float = timeForDuckToReturnPourcent(constant, 50)
    back_99: float = timeForDuckToReturnPourcent(constant, 99)
    back_1_min: float = duck_probability(constant, 1) * 100
    back_2_min: float = duck_probability(constant, 2) * 100
    return DuckInfo(
        average_return, standard_deviation, back_50, back_99, back_1_min, back_2_min
    )


def main(constant: float) -> int:
    info: DuckInfo = get_info(constant)
    display_info(info)
    return 0
