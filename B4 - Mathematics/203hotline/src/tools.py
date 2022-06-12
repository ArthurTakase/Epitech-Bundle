NB_SECOND_IN_8_HOUR: float = 28800.0

NB_SECOND_BY_HOUR: int = 3600

NB_MAX_CALL_BY_DAY: int = 3500

NB_HOTLINE_AVAILABLE: int = 25

NB_HOUR_HOTLINE_WORK_BY_DAY: int = 8


def time_in_second(time: float) -> float:
    return time * 100


def overload_in_percent(overload: float) -> float:
    return overload * 100
