class Pacman():
    def __init__(self, args):
        self.c1 = args.c1
        self.c2 = args.c2
        self.content = []
        self.pacman = None
        self.ghost = None
        self.file = args.file

    def parse_file(self):
        with open(self.file) as file:
            lines = file.readlines()
            for i in range (len(lines)):
                line = lines[i].strip('\n').strip('\r').strip('\n')
                self.content.append([])
                for j in range(len(line)):
                    if lines[i][j] == "F":
                        self.content[i].append(lines[i][j])
                        if self.ghost is None:
                            self.ghost = (j, i, 0)
                        else:
                            return False
                    elif lines[i][j] == "P":
                        self.content[i].append(lines[i][j])
                        if self.pacman is None:
                            self.pacman = (j, i)
                        else:
                            return False
                    elif lines[i][j] == "1":
                        self.content[i].append(-1)
                    elif lines[i][j] == "0":
                        self.content[i].append(-2)
                    else:
                        return False
        
        if self.pacman is None or self.ghost is None:
            return False
        return True
    
    def print(self):
        for elem in self.content:
            for c in elem:
                if c == -1:
                    print(self.c1, end="")
                elif c == -2:
                    print(self.c2, end="")
                elif isinstance(c, int):
                    print(c % 10, end="")
                else:
                    print(c, end="")
            print()

    def compute(self):
        prev = [self.ghost]
        while len(prev) > 0:
            tmp = []
            for posP in prev:
                if (self.checkMap(tmp, posP[0], posP[1] - 1, posP[2]) or
                    self.checkMap(tmp, posP[0] + 1, posP[1], posP[2]) or
                    self.checkMap(tmp, posP[0], posP[1] + 1, posP[2]) or
                    self.checkMap(tmp, posP[0] - 1, posP[1], posP[2])):
                    return
            prev = tmp
    
    def checkMap(self, tmp, x, y, z):
        if (x < 0 or y < 0 or
            x >= len(self.content[y]) or
            y >= len(self.content)):
            return False
        if self.content[y][x] == "P":
            return True
        if self.content[y][x] != -2:
            return False
        self.content[y][x] = z + 1
        tmp.append((x, y, z + 1))