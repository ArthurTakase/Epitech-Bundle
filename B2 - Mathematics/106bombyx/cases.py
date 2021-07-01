#!/usr/bin/env python3


def growth_rate_gen(n: int, k: float) -> None:
    x: float = float(n)
    for i in range(100):
        print(f"{i + 1} {x:.2f}")
        x = k * x * ((1000 - x) / 1000)


def boundary_gen(n: int, i0: int, i1: int) -> None:
    rate: float = 1.0

    while rate < 4:
        bound: int = 1
        result: float = float(n)

        while bound < i0:
            result = rate * result * ((1000 - result) / 1000)
            bound += 1

        while bound <= i1:
            print(f"{rate:.2f} {result:.2f}")
            result = rate * result * ((1000 - result) / 1000)
            bound += 1

        rate += 0.01
