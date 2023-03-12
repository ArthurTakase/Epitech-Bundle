#!/usr/bin/env python3
from src.ai_min_max import AIMinMax
from src.gomoku import Gomoku


def main():
    gomoku: Gomoku = Gomoku(ai=AIMinMax())

    while True:
        command = gomoku.api.get_command()
        gomoku.run_cmd(command)


if __name__ == "__main__":
    main()
