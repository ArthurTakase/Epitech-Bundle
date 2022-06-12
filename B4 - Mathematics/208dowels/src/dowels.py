from typing import List
from math import factorial
from src.display import displayOxTx, displayInfo
from src.merge import getHeaderColumn, uncodeHeader
from src.compute import get_chi_squared


def getTx(header: List[List[int]], p: float) -> List[float]:
    Tx: List[float] = []

    for col in header:
        y = 0
        for data in col:
            C = factorial(100) / (factorial(data) * factorial(100 - data))
            y += C * (p**data) * ((1 - p) ** (100 - data))
        Tx.append(y * 100)

    y: int = 0
    for i in Tx:
        y += i

    Tx.append(Tx.pop() + (100 - y))

    return Tx


def getP(O: List[int]) -> float:
    p: float = 0.0

    for i in range(len(O)):
        p += O[i] * i

    return p / (100**2)


def dowels(O: List[int]) -> int:
    Ox: List[int] = getHeaderColumn(O)
    header: List[List[int]] = uncodeHeader(Ox, O)
    p: float = getP(O)
    Tx: List[float] = getTx(header, p)
    chi_sqr: float = get_chi_squared(Ox, Tx)
    degree_of_freedom: int = len(Ox) - 2
    displayOxTx(header, O, Tx, Ox)
    displayInfo(p, chi_sqr, degree_of_freedom)

    return 0
