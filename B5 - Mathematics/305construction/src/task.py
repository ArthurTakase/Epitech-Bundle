class Task():
    def __init__(self, line):
        # Task infos
        self.id = None
        self.description = None
        self.duration = None
        self.dependencies = None
        self.prerequisites = [[]]
        self.startDate = 0
        self.endDate = 0
        self.fluctuation = 0

        # Task status
        self.line = line
        if not self.parse():
            exit(84)

    def __str__(self):
        if self.endDate != self.startDate:
            return f"{self.id} must begin between t={self.startDate} and t={self.endDate}"
        else:
            return f"{self.id} must begin at t={self.startDate}"


    def parse(self):
        datas = self.line.split(";")

        if len(datas) < 3:
            return False

        self.id = datas[0]
        self.description = datas[1]
        try:
            self.duration = int(datas[2])
        except ValueError:
            return False
        self.dependencies = datas[3:]

        return True
    
    def hasDependencies(self):
        return len(self.dependencies) > 0
    
    def removeDependency(self, id):
        if id in self.dependencies:
            self.dependencies.remove(id)
    
    def grantt(self):
        print(f"{self.id}\t({self.fluctuation})\t{' ' * self.startDate}{'=' * self.duration}")