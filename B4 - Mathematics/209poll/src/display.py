from src.args import Result


def print_result(result: Result) -> None:
    print(f"Population size:\t\t{result.pSize}")
    print(f"Sample size:\t\t\t{result.sSize}")
    print(f"Voting intentions:\t\t{result.P}%")
    print(f"Variance:\t\t\t{result.variance:.6f}")
    print(
        f"95% confidence interval:\t[{result.confidence_interval_95[0]:.2f}%; {result.confidence_interval_95[1]:.2f}%]"
    )
    print(
        f"99% confidence interval:\t[{result.confidence_interval_99[0]:.2f}%; {result.confidence_interval_99[1]:.2f}%]"
    )
