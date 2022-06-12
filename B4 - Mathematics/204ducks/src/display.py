from src.args import DuckInfo


def display_info(info: DuckInfo) -> None:
    print(f"Average return time: {info.average}")
    print(f"Standard deviation: {info.standard_deviation:.3f}")
    print(f"Time after which 50% of the ducks are back: {info.back_50}")
    print(f"Time after which 99% of the ducks are back: {info.back_99}")
    print(f"Percentage of ducks back after 1 minute: {info.back_1_min:.1f}%")
    print(f"Percentage of ducks back after 2 minutes: {info.back_2_min:.1f}%")
