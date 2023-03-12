from itertools import product
from typing import List, NamedTuple

from src.args import Number


class Point(NamedTuple):
    u: Number
    v: Number
    z: Number


def point_at(points_as_number: List[List[Number]], u: int, v: int) -> float:
    points: List[Point] = [Point(point[0], point[1], point[2]) for point in points_as_number]
    return z_from_points(points, u, v)


def constraints_from_file(file_name: str) -> List[Point]:
    constraints: List[Point] = []
    with open(file_name) as file:
        for line in file.readlines():
            point = tuple(map(lambda x: int(x), line.split(";")))
            constraints.append(Point(point[0], point[1], point[2]))
    return constraints


def points_with_constraints(constraints: List[Point], n: int) -> List[Point]:
    points: List[Point] = []
    range_n = range(n)
    for x, y in product(range_n, range_n):
        points.append(Point(x, y, z_from_points(constraints, x, y)))
    return points


def z_from_points(constraints: List[Point], x: int, y: int) -> Number:
    for constraint in constraints:
        if constraint[0] == x and constraint[1] == y:
            return constraint[2]
    return 0
