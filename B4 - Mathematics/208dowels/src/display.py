from typing import List
from src.distribution import get_distribution


def displayOxTx(header: List[List[int]], O: List[int], Tx: List[float], Ox: List[int]):
    # First line
    print("   x\t| ", end="")
    for col in header:
        if col == header[-1]:
            print(f"{col[0]}+", end="")
        elif len(col) == 1:
            print(f"{col[0]}", end="")
        else:
            print(f"{col[0]}-{col[-1]}", end="")
        print("\t| ", end="")
    print("Total")

    # Second Line
    print("  Ox\t| ", end="")
    for data in Ox:
        print(f"{data}\t| ", end="")
    print("100")

    # Last Line
    print("  Tx\t| ", end="")
    for result in Tx:
        print(f"{result:.1f}\t| ", end="")
    print("100")


def displayInfo(p: float, chi_squared: float, degree_of_freedom: int):
    print(f"Distribution:\t\tB(100, {p:.4f})")
    print(f"Chi-squared:\t\t{chi_squared:.3f}")
    print(f"Degrees of freedom:\t{degree_of_freedom}")
    print(
        f"Fit validity:\t\t{get_distribution(degree_of_freedom, chi_squared)}")
