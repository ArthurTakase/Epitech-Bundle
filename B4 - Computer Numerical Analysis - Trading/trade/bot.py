from asyncio.windows_events import NULL
from trade import BotState, truncate
import pandas as pd


class Bot:
    def __init__(self) -> None:
        self.botState = BotState()
        self.window = 30
        self.range = 1.5
        self.current_money = 0
        self.current_btc = 0
        self.current_price = 0
        self.all_prices = []
        self.pricesDataFrame = NULL
        self.sma = NULL
        self.std = NULL
        self.bollinger_up = NULL
        self.bollinger_down = NULL

    def run(self) -> None:
        while True:
            reading = input()
            if len(reading) == 0:
                continue
            self.parse(reading)

    def parse(self, info: str) -> None:
        tmp = info.split(" ")

        if tmp[0] == "settings":
            self.botState.update_settings(tmp[1], tmp[2])
        if tmp[0] == "update":
            if tmp[1] == "game":
                self.botState.update_game(tmp[2], tmp[3])
        if tmp[0] == "action":
            self.current_money = self.botState.stacks["USDT"]
            self.current_btc = self.botState.stacks["BTC"]

            self.updateData()
            self.sell_buy_action()

    def updateData(self):
        try:
            self.current_price = self.botState.charts["USDT_BTC"].closes[-1]
        except:
            pass

        self.all_prices.append(self.current_price)
        self.pricesDataFrame = pd.DataFrame(self.all_prices)
        self.sma = self.pricesDataFrame.rolling(self.window).mean()
        self.std = self.pricesDataFrame.rolling(self.window).std()
        self.bollinger_up = self.sma + self.std * self.range
        self.bollinger_down = self.sma - self.std * self.range

    def sell(self, amount):
        amount = truncate(amount, 6)
        if self.current_btc != 0 and amount > 0:
            print(
                f"sell USDT_BTC {amount}",
                flush=True,
            )
        else:
            print("no_moves", flush=True)

    def buy(self, amount):
        amount = truncate(amount, 6)
        if self.current_money > 0 and amount > 0:
            print(
                f"buy USDT_BTC {amount}",
                flush=True,
            )
        else:
            print("no_moves", flush=True)

    def sell_buy_action(self):
        if self.current_price > self.bollinger_up[0].iloc[-1]:
            self.sell(0.99 * self.current_btc)
        elif self.current_price < self.bollinger_down[0].iloc[-1]:
            self.buy(0.99 * (self.current_money / self.current_price))
        else:
            print("no_moves", flush=True)


if __name__ == "__main__":
    mybot = Bot()
    mybot.run()
