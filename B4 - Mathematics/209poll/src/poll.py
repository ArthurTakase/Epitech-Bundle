from src.args import Arguments, Interval, Result
from src.compute import (
    get_confidence_intervale_95,
    get_confidence_intervale_99,
    get_variance,
)
from src.display import print_result


def poll(args: Arguments) -> int:
    variance: float = get_variance(args.P, args.sSize, args.pSize)
    confidence_interval_95: Interval = get_confidence_intervale_95(variance, args.P)
    confidence_interval_99: Interval = get_confidence_intervale_99(variance, args.P)
    result: Result = Result(
        args.pSize,
        args.sSize,
        args.P,
        variance,
        confidence_interval_95,
        confidence_interval_99,
    )
    print_result(result)
    return 0
