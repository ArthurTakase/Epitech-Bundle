from typing import List
from src.args import Arguments
from typing import List


def display_density(densities: List[float]) -> None:
    for density, x in zip(densities, range(0, 201)):
        print(f"{x} {density:.5f}")


def display_percentage_above_qi(percentage: float, args: Arguments) -> None:
    print(f"{percentage:.1f}% of people have an IQ inferior to {args.IQ1}")


def display_percentage_between_qi(percentage: float, args: Arguments) -> None:
    print(f"{percentage:.1f}% of people have an IQ between {args.IQ1} and {args.IQ2}")
