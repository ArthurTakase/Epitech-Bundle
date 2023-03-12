class PrintSep:
    def __init__(self):
        pass

    def printNames(self, names):
        for name in names:
            print(f"{name}")
        print()

    def printGraph(self, relationships):
        for line in relationships:
            for value in line[:-1]:
                print(value, end=" ")
            print(line[-1])
        print()

    def printDeepGraph(self, deep, maxValue):
        for line in deep:
            for value in line[:-1]:
                print(value if value <= maxValue else "0", end=" ")
            print(line[-1] if line[-1] <= maxValue else "0")

    def printSepBetween(self, first, second, sep):
        print(f"Degree of separation between {first} and {second}: {sep}")
