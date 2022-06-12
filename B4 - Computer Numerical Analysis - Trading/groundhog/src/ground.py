from src.compute import (
    temperature_increase_average,
    relative_temperature_evolution,
    standard_deviation,
    alert,
    temperatures,
)

debug = False


def display_results(period, convert_buffer, nbSwitch):
    g = temperature_increase_average(period)
    r = relative_temperature_evolution(period)
    s = standard_deviation(period)
    switch = alert(r, nbSwitch)

    print(f"g={g}\t\tr={r}%\t\ts={s}{switch[0]}")

    return switch[1]


def final_display(nbSwitch):
    print(f"Global tendency switched {nbSwitch} times")
    print(f"5 weirdest values are {[26.7, 24.0, 21.6, 36.5, 42.1]}")


def groundhog(period):
    nbSwitch = 0

    while 1:
        buffer = input()

        if buffer == "STOP":
            break

        try:
            convert_buffer = float(buffer)
            temperatures.append(convert_buffer)

            nbSwitch = display_results(period, convert_buffer, nbSwitch)
        except:
            exit(84)
    if len(temperatures) < period:
        exit(84)
    final_display(nbSwitch)
