from itertools import product
from typing import List

from src.args import Number
from src.math import bernstein
from src.points import Point, point_at


class BezierSurface:
    def __init__(self, points: List[Point], n: int) -> None:
        self.n: int = n
        self.points: List[List[Number]] = [list(point) for point in points]

    def __call__(self, u: Number, v: Number) -> float:
        n: int = self.n
        z: float = sum(
            bernstein(n - 1, i, u) * bernstein(n - 1, j, v) * point_at(self.points, i, j) for i, j in product(range(n), range(n))
        )
        return z
