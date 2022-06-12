from time import time
from typing import List
from src.args import ResultDistribution
from src.display import display_distributions
from src.binomial import binomial
from src.poisson import poisson
from src.tools import (
    NB_HOTLINE_AVAILABLE,
    NB_HOUR_HOTLINE_WORK_BY_DAY,
    NB_MAX_CALL_BY_DAY,
    NB_SECOND_BY_HOUR,
    NB_SECOND_IN_8_HOUR,
    time_in_second,
    overload_in_percent,
)


def duration(duration: float) -> int:
    binomial: ResultDistribution = binomial_distribution(duration)
    poisson: ResultDistribution = poisson_distribution(duration)
    display_distributions(binomial, poisson)
    return 0


def binomial_distribution(duration: float) -> ResultDistribution:
    start: float = time()
    overload: float = 0.0
    duration /= NB_SECOND_IN_8_HOUR
    n: int = NB_MAX_CALL_BY_DAY
    list_k: List[int] = [k for k in range(51)]
    res: List[float] = []

    for k in list_k:
        temp: float = (binomial(n, k) * (duration**k)) * ((1 - duration) ** (n - k))
        res.append(temp)
        if k > NB_HOTLINE_AVAILABLE:
            overload += temp
    end: float = time()
    return ResultDistribution(
        overload_in_percent(overload), time_in_second(end - start), res
    )


def poisson_distribution(duration: float) -> ResultDistribution:
    start: float = time()
    overload: float = 0.0
    duration /= NB_SECOND_BY_HOUR
    _lambda = (duration * NB_MAX_CALL_BY_DAY) / NB_HOUR_HOTLINE_WORK_BY_DAY
    list_k: List[int] = [k for k in range(51)]
    res: List[float] = []

    for k in list_k:
        temp: float = poisson(k, _lambda)
        res.append(temp)
        if k > NB_HOTLINE_AVAILABLE:
            overload += temp
    end: float = time()
    return ResultDistribution(
        overload_in_percent(overload), time_in_second(end - start), res
    )
