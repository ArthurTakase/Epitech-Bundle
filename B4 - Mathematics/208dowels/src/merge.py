from typing import List


def mergeWithAround(index: int, liste: List[int]) -> List[int]:
    if index == 0 and len(liste) > 1:
        liste[index] += liste[index + 1]
        liste.pop(index + 1)
        return liste
    if (index == len(liste) - 1) and len(liste) > 1:
        liste[index] += liste[index - 1]
        liste.pop(index - 1)
        return liste
    if liste[index - 1] < liste[index + 1]:
        liste[index] += liste[index - 1]
        liste.pop(index - 1)
        return liste
    liste[index] += liste[index + 1]
    liste.pop(index + 1)
    return liste


def uncodeHeader(header: List[int], O: List[int]) -> List[List[int]]:
    newHeader: List[List[int]] = []
    i: int = 0
    j: int = 0

    while i < len(header):
        tempHeader: List[int] = []

        if header[i] != O[j]:
            tempO: int = O[j]
            tempHeader.append(j)
            while tempO != header[i]:
                j += 1
                tempO += O[j]
                tempHeader.append(j)
            newHeader.append(tempHeader)
        else:
            newHeader.append([j])
        i += 1
        j += 1

    return newHeader


def getHeaderColumn(O: List[int]) -> List[int]:
    """
    fusionne les cases jusqu'à ce que leur somme soit supérieure ou égale à 10.
    """
    Ox: List[int] = O.copy()

    minO: int = min(Ox)
    while minO < 10:
        index = Ox.index(minO)
        Ox = mergeWithAround(index, Ox)
        minO = min(Ox)

    return Ox
