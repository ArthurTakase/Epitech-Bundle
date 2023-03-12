from typing import List

from src.args import Arguments, Number
from src.bezierSurface import BezierSurface
from src.points import Point, constraints_from_file, points_with_constraints
from src.print import print_result


def main(args: Arguments) -> int:
    u: Number = args.x / (args.n - 1)
    v: Number = args.y / (args.n - 1)

    constraints: List[Point] = constraints_from_file(args.file_name)
    points: List[Point] = points_with_constraints(constraints, args.n)

    bezier: BezierSurface = BezierSurface(points, args.n)
    result: float = bezier(u, v)
    print_result(result)

    return 0
