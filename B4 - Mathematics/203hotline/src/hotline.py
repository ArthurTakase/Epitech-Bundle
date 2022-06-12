from src.args import Argument, Binomial, CallDuration
from src.binomial import binomial_computation
from src.duration import duration


def main(args: Argument) -> int:
    if isinstance(args.args, Binomial):
        return binomial_computation(args.args.n, args.args.k)
    if isinstance(args.args, CallDuration):
        return duration(args.args)
    return 84
