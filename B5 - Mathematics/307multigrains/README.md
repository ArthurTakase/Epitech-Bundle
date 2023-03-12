# Multigrains Production System

This is a Python program that models a system for producing four types of grains (oat, wheat, corn, and barley). It uses linear programming to find the optimal production of the grains given a set of resources and prices.

## Requirements

* Python 3.x

## Usage

To use the program, create an instance of the `Multigrains` class with a list of the following information:

* Four integers representing the resources available for producing the grains (in the order F1, F2, F3, F4).
* Five integers representing the prices of the grains (in the order oats, wheat, corn, barley, soy).

For example:

```python
mg = Multigrains([20, 20, 10, 10, 3, 4, 6, 5, 7])
```

The program will then calculate the optimal production of the grains and print the results to the console. The results include the production and price of each grain, as well as the total production value.

## Example Output

```bash
Resources: 20 F1, 20 F2, 10 F3, 10 F4

Oat: 1.50 units at $3/unit
Wheat: 2.50 units at $4/unit
Corn: 2.50 units at $6/unit
Barley: 0.50 units at $5/unit

Total production value: $30.00
```

## Note

The program uses the simplex method to solve the linear programming problem. If the problem is not in standard form (i.e., all variables are non-negative and the objective function is to be maximized), the program will transform the problem into standard form using the dual simplex method.

---

## Pseudo-code Multigrains

### Main Loop

```python
while any value in self.matrix[-1] is less than 0:
    # Call applyPivot with the result of getPivot as the argument
    self.applyPivot(self.getPivot())
```

### GetPivot

```python
# Find the lowest price in the last row of the matrix
lowestPrice = minimum value in self.matrix[-1]
# Find the index of the lowest price in the last row of the matrix
lowestPriceIdx = index of lowestPrice in self.matrix[-1]
  
# Initialize an empty list to store tuples
storageValues = []
# Iterate through all rows in the matrix except for the last row
for i in range 0 to number of rows in self.matrix - 1:
    # If the value in the current row at the lowestPriceIdx is not 0
    if self.matrix[i][lowestPriceIdx] is not 0:
        # Calculate the ratio of the value in the first column of the current row divided by the value in the current row at the lowestPriceIdx
        ratio = self.matrix[i][0] / self.matrix[i][lowestPriceIdx]
        # Create a tuple consisting of the ratio and a tuple of the current row and column indices
        tup = (ratio, (i, lowestPriceIdx))
        # Add the tuple to the storageValues list
        storageValues.append(tup)
  
# Create a new list consisting of tuples from storageValues where the ratio is greater than or equal to 0
newList = tuples in storageValues where ratio is greater than or equal to 0
# Return the minimum tuple in the newList
return minimum tuple in newList
```

### ApplyPivot

```python
# Set the element at the pivot row and base column to the string value at the corresponding index in self.basesStrings
self.bases[pivotInfos[1][0]] = self.basesStrings[pivotInfos[1][1] - 1]
# Set pivotValue to the value in the pivot row and column
pivotValue = value in self.matrix at pivotInfos[1][0] and pivotInfos[1][1]
# Set the values in the pivot row to the result of dividing each value in the row by pivotValue
self.matrix[pivotInfos[1][0]] = [x / pivotValue for x in self.matrix[pivotInfos[1][0]]]
# Iterate through all rows in the matrix
for i, row in enumerate 0 to number of rows in self.matrix:
    # If the current row is the pivot row, skip it
    if i is pivotInfos[1][0]:
        continue
    # Set pivotValue to the value in the current row at the pivot column
    pivotValue = value in row at pivotInfos[1][1]
    # Set the values in the current row to the result of subtracting each value in the pivot row multiplied by pivotValue from the corresponding value in the current row
    self.matrix[i] = [x - pivotValue * y for x, y in zip(row, self.matrix[pivotInfos[1][0]])]

```
