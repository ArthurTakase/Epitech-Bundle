from src.args import Array, Numeric


class Sort:
    def __init__(self, array):
        self.array = array
        self.selectionCount = 0
        self.insertionCount = 0
        self.bubbleCount = 0
        self.quickCount = 0
        self.mergeCount = 0

    def sort(self):
        self.selectionSort()
        self.insertionSort()
        self.bubbleSort()
        self.mergeSort(self.array.copy())
        self.quickSort(self.array.copy())

    def selectionSort(self):
        array = self.array.copy()

        for i in range(len(array)):
            min = i
            for j in range(i + 1, len(array)):
                self.selectionCount += 1
                if array[min] > array[j]:
                    min = j
            array[i], array[min] = array[min], array[i]

    def insertionSort(self):
        array = self.array.copy()
        sort = [array[0]]

        for n in range(1, len(array)):
            isInsert = False
            for i in range(len(sort)):
                self.insertionCount += 1
                if array[n] < sort[i]:
                    sort.insert(i, array[n])
                    isInsert = True
                    break
            if not isInsert:
                sort.append(array[n])

    def bubbleSort(self):
        array = self.array.copy()

        for i in range(len(array) - 1):
            for j in range(len(array) - 1 - i):
                self.bubbleCount += 1
                if array[j] > array[j + 1]:
                    array[j], array[j + 1] = array[j + 1], array[j]

    def quickSort(self, arr: Array):
        if len(arr) < 2:
            return 0
        pivot = arr[0]
        left, right = [], []
        for i in range(1, len(arr)):
            left.append(arr[i]) if arr[i] < pivot else right.append(arr[i])
            self.quickCount += 1

        self.quickSort(right)
        self.quickSort(left)

    def mergeSort(self, array):
        if len(array) > 1:
            mid = len(array) // 2
            left, right = array[:mid], array[mid:]

            self.mergeSort(left)
            self.mergeSort(right)

            i = j = k = 0

            while i < len(left) and j < len(right):
                self.mergeCount += 1
                if left[i] < right[j]:
                    array[k] = left[i]
                    i += 1
                else:
                    array[k] = right[j]
                    j += 1
                k += 1

            while i < len(left):
                array[k] = left[i]
                i += 1
                k += 1

            while j < len(right):
                array[k] = right[j]
                j += 1
                k += 1

    def __str__(self):
        return f"""{len(self.array)} element{'s' if len(self.array) != 1 else ''}
Selection sort: {self.selectionCount} comparisons
Insertion sort: {self.insertionCount} comparisons
Bubble sort: {self.bubbleCount} comparisons
Quicksort: {self.quickCount} comparisons
Merge sort: {self.mergeCount} comparisons"""
