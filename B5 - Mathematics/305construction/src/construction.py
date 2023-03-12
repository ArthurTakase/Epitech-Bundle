class Construction():
    def __init__(self, args):
        self.tasks = args
        self.temp = []
        self.globalDuration = 0

    def print(self):
        print(f"Total duration of construction: {self.globalDuration} weeks\n")
        for i in self.temp:
            print(i)
        print()
        for i in self.temp:
            i.grantt()

    def needsRec(self, original, name):
        for i in self.tasks[name].dependencies:
            self.tasks[original].prerequisites[-1].append(i)
            self.needsRec(original, i)
        self.tasks[original].prerequisites.append([])
    
    def startDate(self):
        for i in self.tasks:
            tmp = 0
            duration = 0
            for d in self.tasks[i].prerequisites:
                for e in d: duration += self.tasks[e].duration
                if duration > tmp: tmp = duration
                duration = 0
            self.tasks[i].startDate = tmp

    def endDate(self):
        for task in self.temp:
            deadline = self.globalDuration
            for t in self.temp:
                if (deadline > t.startDate and task.id in t.dependencies):
                    deadline = t.startDate
            task.fluctuation = deadline - (task.startDate + task.duration)
            task.endDate = task.startDate + task.fluctuation

    def compute(self):
        # Liste des besoins
        for ky in self.tasks:
            self.needsRec(ky, ky)
            self.tasks[ky].prerequisites = [i for i in self.tasks[ky].prerequisites if i]
        
        self.startDate()

        # Tri des tâches par date de début, durée et nom
        self.temp = [task for task in self.tasks.values()]
        self.temp.sort(key=lambda x: (x.startDate, x.duration, x.id))

        # Calcul de la durée totale
        self.globalDuration = self.temp[-1].startDate + self.temp[-1].duration

        self.endDate()