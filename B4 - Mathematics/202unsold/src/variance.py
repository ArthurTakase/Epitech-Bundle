from typing import List
from src.args import Variance


def calcul_variance(X_law: List[float], Y_law: List[float]) -> Variance:
    expX: float = 0.0
    expY: float = 0.0
    totalX: float = 0.0
    totalY: float = 0.0

    for i in range(0, 5):
        totalX += X_law[i] * ((i + 1) * 10)
        totalY += Y_law[i] * ((i + 1) * 10)
    for i in range(0, 5):
        expX += ((i + 1) * 10 - totalX) * ((i + 1) * 10 - totalX) * X_law[i]
        expY += ((i + 1) * 10 - totalY) * ((i + 1) * 10 - totalY) * Y_law[i]
    return Variance(
        totalX,
        totalY,
        expX,
        expY,
    )
