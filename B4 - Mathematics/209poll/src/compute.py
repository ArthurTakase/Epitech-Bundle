from math import sqrt
from src.args import Interval


def get_variance(p: float, sSize: float, pSize: float) -> float:
    p /= 100
    return (p * (1 - p)) / sSize * (pSize - sSize) / (pSize - 1)


def get_confidence_intervale_95(variance: float, percentage: float) -> Interval:
    conf: float = 1.96 * sqrt(variance) * 100
    return (percentage - conf, percentage + conf)


def get_confidence_intervale_99(variance: float, percentage: float) -> Interval:
    conf: float = 2.58 * sqrt(variance) * 100
    return (percentage - conf, percentage + conf)
