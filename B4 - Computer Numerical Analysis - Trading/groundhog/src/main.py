#! /usr/bin/python3

from sys import argv
from src.ground import groundhog


def help():
    print("SYNOPSIS")
    print("\t./groundhog period\n")
    print("DESCRIPTION")
    print("\tperiod\tthe number of days defining a period")


if __name__ == "__main__":
    if len(argv) == 1 or "-h" in argv:
        help()
        exit(84)
    else:
        try:
            period = int(argv[1])
            groundhog(period)
        except:
            help()
            exit(84)
