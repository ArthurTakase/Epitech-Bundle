class Separation:
    def __init__(self, file):
        self.filename = file
        self.relations = {}
        self.names = []
        self.relationships = []
        self.deep = []

        self.loadFile()
        self.names = sorted(self.relations.keys())
    
    def loadFile(self):
        with open(self.filename, "r") as file:
            lines = file.readlines()
            for line in lines:
                try:
                    first, second = line.strip().split(" is friends with ")
                except:
                    continue
                if first in self.relations:
                    self.relations[first].append(second)
                else:
                    self.relations[first] = [second]
                if second in self.relations:
                    self.relations[second].append(first)
                else:
                    self.relations[second] = [first]

    def isFriend(self, first, second):
        if second in self.relations[first]:
            return 1
        return 0

    def createGraph(self):
        for name in self.names:
            self.relationships.append(
                [self.isFriend(name, friend) for friend in self.names]
            )

    def createDeepGraph(self):
        nbRelation = len(self.relationships)
        self.deep = [[nbRelation] * nbRelation for i in range(0, nbRelation)]

        for i in range(0, nbRelation):
            for j in range(0, nbRelation):
                if self.relationships[i][j] > 0:
                    self.deep[i][j] = 1
            self.deep[i][i] = 0

        for k in range(0, nbRelation):
            for i in range(0, nbRelation):
                for j in range(0, nbRelation):
                    self.deep[i][j] = min(self.deep[i][j], self.deep[i][k] + self.deep[k][j])

    def sepBetween(self, first, second):
        if first not in self.names or second not in self.names:
            return -1
        return self.deep[self.names.index(first)][self.names.index(second)]