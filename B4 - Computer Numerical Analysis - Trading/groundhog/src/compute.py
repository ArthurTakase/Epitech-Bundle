from math import sqrt

temperatures = []
previousR = 0


def temperature_increase_average(period):
    g = 0.0

    if len(temperatures) > period:
        for i in range(len(temperatures) - period, len(temperatures)):
            n = temperatures[i] - temperatures[i - 1]
            g += n if n > 0 else 0
        try:
            return f"{g / period:.2f}"
        except:
            return f"{0:.2f}"
    else:
        return "nan"


def relative_temperature_evolution(period):
    if len(temperatures) > period:
        var1 = temperatures[len(temperatures) - period - 1]
        var2 = temperatures[-1]
        try:
            return round((var2 - var1) / var1 * 100)
        except:
            return 0
    else:
        return "nan"


def standard_deviation(period):
    if len(temperatures) >= period:
        x, y = 0, 0

        for i in range(len(temperatures) - period, len(temperatures)):
            x += temperatures[i]
            y += pow(temperatures[i], 2)
        return f"{sqrt(y / period - pow(x / period, 2)):.2f}"
    else:
        return "nan"


def alert(r, nbSwitch):
    global previousR
    result = ""

    try:
        if previousR < 0 and r > 0:
            result = "\t\ta switch occurs"
            nbSwitch += 1
        elif previousR > 0 and r < 0:
            result = "\t\ta switch occurs"
            nbSwitch += 1
    except:
        pass

    previousR = r

    return [result, nbSwitch]
