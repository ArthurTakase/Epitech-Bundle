from src.args import Arguments, Neutrino
from src.compute import compute_values


def display(values: Neutrino) -> None:
    print(f"\tNumber of values:\t{values.n:.0f}")
    print(f"\tStandard deviation:\t{values.sd:.2f}")
    print(f"\tArithmetic mean:\t{values.a:.2f}")
    print(f"\tRoot mean square:\t{values.new_root:.2f}")
    print(f"\tHarmonic mean:\t\t{values.h:.2f}\n")


def neutrinos(args: Arguments) -> None:
    values: Neutrino = Neutrino(args.n, args.a, args.h, args.sd)

    while 1:
        buffer = input("Enter next value: ")

        if buffer == "END":
            break

        try:
            compute_values(values, float(buffer))
            display(values)
        except:
            exit(84)
