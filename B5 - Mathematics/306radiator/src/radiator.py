class Radiator:
    def __init__(self, args):
        self.s = args.size
        self.ir = args.ir
        self.jr = args.jr
        self.i = args.i
        self.j = args.j
        self.n = self.s ** 2
        self.r = self.ir + self.jr * self.s
        self.map = None
        self.N = None
        self.T = None

    # ------------------------------------------------------------------------

    def printMap(self):
        for a in self.map:
            print('\t'.join('%d' % r for r in a))
        print()
    
    def printVector(self):
        for t in self.T:
            print(f"{round(t, 1):.1f}")
    
    def printI(self):
        if not all(0 <= x <= (self.s - 1) for x in (self.i, self.j)):
            exit(84)
        print(f"{round(self.T[self.i + self.j * self.s], 1):.1f}")
    
    # ------------------------------------------------------------------------

    def term(self, i, j):
        if not all(1 <= x <= (self.s - 2) for x in (i % self.s, i // self.s)):
            return 1 if i == j else 0
        else:
            a = abs(i - j)
            if a == 0:
                return -16
            if a == 1 or a == self.s:
                return 4
            return 0

    def computeMap(self):
        self.map = [[self.term(i, j) for j in range(self.n)] for i in range(self.n)]
        self.N = list(range(self.n))

    def computeVector(self):
        for i in range(self.n):
            self.map[i].append(-300 if i == self.r else 0)

        for k in range(self.n):
            for i in range(k, self.n):
                if abs(self.map[i][k]) > abs(self.map[k][k]):
                    self.map[k], self.map[i] = self.map[i], self.map[k]
                    self.N[k], self.N[i] = self.N[i], self.N[k]
            for i in range(k + 1, self.n):
                f = self.map[i][k] / self.map[k][k]
                for j in range(k, self.n + 1):
                    self.map[i][j] -= f * self.map[k][j]

        self.T = [0.0] * self.n
        self.T[self.n - 1] = self.map[self.n - 1][self.n] / self.map[self.n - 1][self.n - 1]
        for i in reversed(range(self.n)):
            c = 0.0
            for j in range(i + 1, self.n):
                c += self.map[i][j] * self.T[j]
            self.T[i] = (self.map[i][self.n] - c) / self.map[i][i]