from typing import List


def new_matrix(n: int) -> List[List[float]]:
    matrice: List[List[float]] = []
    for row in range(n):
        matrice.append([0 for col in range(n)])
    return matrice


def print_matrix(matrix: List[List[float]]) -> None:
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if j == len(matrix[0]) - 1:
                print(f"{matrix[i][j]:.2f}", end="")
            else:
                print(f"{matrix[i][j]:.2f}\t", end="")
        print()


def mul_matrix(A: List[List[float]], B: List[List[float]]) -> List[List[float]]:
    matrix = new_matrix(len(A))

    for i in range(len(A)):
        for j in range(len(B[0])):
            matrix[i][j] = 0
    for i in range(len(A)):
        for j in range(len(B)):
            for k in range(len(A)):
                matrix[i][j] += A[i][k] * B[k][j]
    return matrix


def divide_matrix(matrice: List[List[float]], n: float) -> List[List[float]]:
    if n == 0:
        exit(84)
    for i in range(len(matrice)):
        for j in range(len(matrice[i])):
            matrice[i][j] /= n
    return matrice


def substract_matrix(
    matrice1: List[List[float]], matrice2: List[List[float]]
) -> List[List[float]]:
    temp: List[List[float]] = new_matrix(len(matrice1))
    for i in range(len(matrice1)):
        for j in range(len(matrice1)):
            temp[i][j] = matrice1[i][j] - matrice2[i][j]
    return temp


def add_matrix(
    matrice1: List[List[float]], matrice2: List[List[float]]
) -> List[List[float]]:
    temp: List[List[float]] = new_matrix(len(matrice1))
    for i in range(len(matrice1)):
        for j in range(len(matrice1)):
            temp[i][j] = matrice1[i][j] + matrice2[i][j]
    return temp


def power_matrix(matrice: List[List[float]], n: int) -> List[List[float]]:
    temp: List[List[float]] = matrice
    for i in range(n - 1):
        temp = mul_matrix(temp, matrice)
    return temp


def base_matrix(n: int) -> List[List[float]]:
    tmp: List[List[float]] = new_matrix(n)

    for i in range(n):
        for j in range(n):
            if j == i:
                tmp[i][j] = 1
            else:
                tmp[i][j] = 0
    return tmp
