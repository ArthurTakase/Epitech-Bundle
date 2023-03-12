class Multigrains:
    def __init__(self, infos: list) -> None:
        self.resources = infos[:4]
        self.grainsPrices = infos[4:]
        self.basesStrings = ["Oat", "Wheat", "Corn", "Barley", "Soy"]
        self.bases = [None, None, None, None]
        self.matrix = [
            [infos[0], 1, 0, 1, 0, 2, 1, 0, 0, 0],
            [infos[1], 1, 2, 0, 1, 0, 0, 1, 0, 0],
            [infos[2], 2, 1, 0, 1, 0, 0, 0, 1, 0],
            [infos[3], 0, 0, 3, 1, 2, 0, 0, 0, 1],
            [0, -infos[4], -infos[5], -infos[6], -infos[7], -infos[8], 0, 0, 0, 0]
        ]

        while any(n < 0 for n in self.matrix[-1]): self.applyPivot(self.getPivot())
        self.display()

    def getPivot(self):
        lowestPrice = min(self.matrix[-1])
        lowestPriceIdx = self.matrix[-1].index(lowestPrice)
        storageValues = [(self.matrix[i][0] / self.matrix[i][lowestPriceIdx], (i, lowestPriceIdx)) for i in range(len(self.matrix) - 1) if self.matrix[i][lowestPriceIdx] != 0]
        newList = [tup for tup in storageValues if tup[0] >= 0]
        return min(newList)

    def applyPivot(self, pivotInfos):
        self.bases[pivotInfos[1][0]] = self.basesStrings[pivotInfos[1][1] - 1]
        pivotValue = self.matrix[pivotInfos[1][0]][pivotInfos[1][1]]
        self.matrix[pivotInfos[1][0]] = [x / pivotValue for x in self.matrix[pivotInfos[1][0]]]
        for i, row in enumerate(self.matrix):
            if i == pivotInfos[1][0]: continue
            pivotValue = row[pivotInfos[1][1]]
            self.matrix[i] = [x - pivotValue * y for x, y in zip(row, self.matrix[pivotInfos[1][0]])]

    def getProd(self, grain: str) -> float:
        return "0" if grain not in self.bases or self.matrix[self.bases.index(grain)][0] == 0 else f"{self.matrix[self.bases.index(grain)][0]:.2f}"

    def display(self):
        grains = [('Oat', self.grainsPrices[0]), ('Wheat', self.grainsPrices[1]), ('Corn', self.grainsPrices[2]), ('Barley', self.grainsPrices[3]), ('Soy', self.grainsPrices[4])]

        print(f"Resources: {self.resources[0]} F1, {self.resources[1]} F2, {self.resources[2]} F3," f" {self.resources[3]} F4\n")
        for grain, price in grains: print(f"{grain}: {self.getProd(grain)} units at ${price}/unit")
        print(f"\nTotal production value: ${self.matrix[-1][0]:.2f}")