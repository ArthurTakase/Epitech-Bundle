import matplotlib.pyplot as plt
from close import close
from close2 import close2
import pandas as pd


def get_sma(window, values):
    return values.rolling(window).mean()


def get_rolling_standard_deviation(window, values):
    return values.rolling(window).std()


def matplot():

    dataset = close

    all_prices = []

    for i in range(len(dataset)):
        all_prices.append(dataset[i])

        temp = pd.DataFrame(all_prices)
        sma = get_sma(20, temp)
        std = get_rolling_standard_deviation(20, temp)

        bollinger_up = sma + std * 2
        bollinger_down = sma - std * 2

        if dataset[i] > bollinger_up[0].iloc[-1]:
            plt.scatter(i, all_prices[i], color="red")
            print("Sell")
        elif dataset[i] < bollinger_down[0].iloc[-1]:
            plt.scatter(i, all_prices[i], color="lightgreen")
            print("Buy")

    plt.scatter(-1, -1, color="red", label="Sell")
    plt.scatter(-1, -1, color="lightgreen", label="Buy")

    plt.plot(pd.DataFrame(all_prices), color="lightgrey", label="Prices")
    plt.plot(sma, color="blue", label="SMA")
    plt.plot(bollinger_up, color="green", label="Bollinger Up")
    plt.plot(bollinger_down, color="red", label="Bollinger Down")
    plt.legend()
    plt.show()


matplot()
