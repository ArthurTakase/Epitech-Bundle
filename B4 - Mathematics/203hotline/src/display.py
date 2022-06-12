from src.args import ResultDistribution


def display_binomial(n: int, k: int, res: int) -> None:
    print(f"{k}-combinations of a set of size {n}:")
    print(res)


def display_distributions(
    binomial: ResultDistribution, poisson: ResultDistribution
) -> None:
    print("Binomial distribution:")
    display_distribution(binomial)
    print("")
    print("Poisson distribution:")
    display_distribution(poisson)


def display_distribution(result: ResultDistribution) -> None:
    i: int = 1
    for nb in result.distribution[:-1]:
        if i % 5 == 0:
            print(f"{i - 1} -> {nb:.3f}")
        else:
            print(f"{i -1} -> {nb:.3f}", end="\t")
        i += 1
    print(f"{i-1} -> {result.distribution[-1]:.3f}")
    print(f"Overload: {result.overload:.1f}%")
    print(f"Computation time: {result.time:.1f} ms")
