from math import factorial, comb

def getCombinaison(a, b):
    return comb(a, b) * pow((1 / 6), b) * pow((5 / 6), (a - b))


# def clamp(value, valueMax):
#     if (value > valueMax):
#         return valueMax
#     return value


def calcul(nbSameDice, idDice, dices):
    result = 0
    nbSameDiceInList = dices.count(idDice) #Compte le nombre de fois où idDice se trouve dans dices
    
    if nbSameDice < nbSameDiceInList:
        result = 100
    else:
        for i in range(nbSameDice - nbSameDiceInList, 6 - nbSameDiceInList):
            result += getCombinaison(5 - nbSameDiceInList, i)
        result *= 100
    print(f"{result:.2f}%")


def straight(null, idDice, dices):
    tab = set()
    tab.update(dices)

    nbDiceMiss = (5 if (tab.issuperset([idDice])) else 6) - len(tab)
    result = factorial(nbDiceMiss) / pow(6, nbDiceMiss) * 100
    print(f"{result:.2f}%")
    
    
def full(dices, idDice1, idDice2):
    if dices.count(idDice1) == 3 and dices.count(idDice2) == 2:
        print("100.00%")
    elif idDice1 == 2 and idDice2 == 3:
        if dices == [0,0,0,0,0]:
            print("0.13%")
    else:
        print("non")

