from typing import Dict, List
from src.args import Argument
from src.compute import compute_splines, compute_vector
from src.print import print_result, print_vector


def main(args: Argument) -> int:
    constraints: List[float] = get_constraints_from_args(args)
    var: Dict[str, int] = dict_from_args(args)
    vector: List = compute_vector(var)
    abscisses: List[float] = [0, 5, 10, 15, 20]

    result = compute_splines(vector, constraints, abscisses, args.n)
    print_vector(vector)
    print_result(result, args.n)
    return 0


def get_constraints_from_args(args: Argument) -> List[float]:
    return [float(args.r0), float(args.r5), float(args.r10), float(args.r15), float(args.r20)]


def dict_from_args(args: Argument) -> Dict:
    return {"r0": args.r0, "r5": args.r5, "r10": args.r10, "r15": args.r15, "r20": args.r20}
