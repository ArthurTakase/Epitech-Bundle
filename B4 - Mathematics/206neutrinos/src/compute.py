from math import sqrt
from src.args import Neutrino


def quadratiq_mean(args: Neutrino, my_buffer: float) -> float:
    return (
        (((args.sd) ** 2 + (args.a) ** 2) * (args.n - 1)) + (my_buffer) ** 2
    ) / args.n


def root_mean(values: Neutrino, my_buffer: float) -> float:
    return sqrt(quadratiq_mean(values, my_buffer))


def arithmetic_mean(values: Neutrino, my_buffer: float) -> float:
    return ((values.a * (values.n - 1)) + my_buffer) / values.n


def standard_deviation(values: Neutrino, my_buffer: float) -> float:
    return sqrt(
        quadratiq_mean(values, my_buffer) - (arithmetic_mean(values, my_buffer) ** 2)
    )


def harmonic_mean(values: Neutrino, my_buffer: float) -> float:
    return values.n / (1 / my_buffer + (values.n - 1) / values.h)


def compute_values(values: Neutrino, my_buffer: float) -> None:
    values.new_root = root_mean(values, my_buffer)
    values.sd = standard_deviation(values, my_buffer)
    values.a = arithmetic_mean(values, my_buffer)
    values.h = harmonic_mean(values, my_buffer)
    values.n += 1
