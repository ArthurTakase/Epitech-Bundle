from typing import List
from src.args import Laws, Variance
from src.laws import calculate


def display(tabs: List[List[float]], laws: Laws, variance: Variance) -> None:
    print_line()
    display_probability(tabs, laws)
    print_line()
    display_laws(tabs)
    print_line()
    display_variance(variance)
    print_line()


def print_line() -> None:
    line = "-" * 80
    print(f"{line}")


def display_probability(tabs: List[List[float]], laws: Laws) -> None:
    X_law = laws.x.copy()
    row_names: List[str] = ["Y=10", "Y=20", "Y=30", "Y=40", "Y=50"]

    print("\tX=10\tX=20\tX=30\tX=40\tX=50\tY law")
    for tab in tabs:
        print(f"{row_names[tabs.index(tab)]}\t", end="")
        for nb in tab:
            print(f"{nb:.3f}\t", end="")
        print(f"{X_law.pop(0):.3f}")
    display_y_sum(laws.y)


def display_y_sum(Y_law: List[float]) -> None:
    print("X law\t", end="")
    for y in Y_law:
        print(f"{y:.3f}\t", end="")
    print("1.000")


def display_laws(tab: List[List[float]]) -> None:
    print("z\t20\t30\t40\t50\t60\t70\t80\t90\t100\np(Z=z)", end="")
    for z in range(20, 110, 10):
        print(f"\t{calculate(tab, z):.3f}", end="")
    print("")


def display_variance(variance: Variance) -> None:
    print(f"expected value of X:\t{variance.totalY:.1f}")
    print(f"variance of X:\t\t{variance.expY:.1f}")
    print(f"expected value of Y:\t{variance.totalX:.1f}")
    print(f"variance of Y:\t\t{variance.expX:.1f}")
    print(f"expected value of Z:\t{variance.totalX + variance.totalY:.1f}")
    print(f"variance of Z:\t\t{variance.expX + variance.expY:.1f}")
