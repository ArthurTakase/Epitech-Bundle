from math import sqrt, exp


def convert_time(time: float) -> str:
    time = round((time * 60 / 100) * 100)
    minutes: int = int(time / 60)
    seconds: int = int(time % 60)
    if seconds < 10:
        return f"{minutes}m 0{seconds}s"
    return f"{minutes}m {seconds}s"


def duck_probability_calc(a: float, t: float) -> float:
    return -a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t)


def duck_probability(a: float, t: float) -> float:
    return duck_probability_calc(a, t) - duck_probability_calc(a, 0)


def esperance(a: float) -> float:
    res: float = (a + (4 - 3 * a) / 4) + ((2 * a - 4) / 16)
    return res


def variance(a: float) -> float:
    res: float = (2 * a) + (2 * (4 - 3 * a)) / 8 + 2 * (2 * a - 4) / 64
    res -= esperance(a) ** 2
    return round(sqrt(res), 3)


def timeForDuckToReturnPourcent(a: float, pourcent: int) -> float:
    res: float = 0.0
    while duck_probability(a, res) <= pourcent / 100:
        res += 0.001
    return convert_time(res)
