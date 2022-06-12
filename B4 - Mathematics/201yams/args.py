from sys import argv

def myExit(locate):
    print(f"Stop doing n'importe quoi ! (╬▔皿▔)╯ ({locate})")
    return 84


def getArgs():
    if "-h" in argv:
        print("""USAGE
\t./201yams d1 d2 d3 d4 d5 c
DESCRIPTION
\td1\tvalue of the first die (0 if not thrown)
\td2\tvalue of the second die (0 if not thrown)
\td3\tvalue of the third die (0 if not thrown)
\td4\tvalue of the fourth die (0 if not thrown)
\td5\tvalue of the fifth die (0 if not thrown)
\tc\texpected combination""")
        return 0
    if len(argv) != 7 or "_" not in argv[6]:
        return myExit("pas de '_' ou mauvais nombre d'args")
    try :
        dices = [int(argv[1]), int(argv[2]), int(argv[3]), int(argv[4]), int(argv[5])]
    except:
        return myExit("Les dés doivent être des Int")
    for i in range(5):
        if (dices[i] > 6 or dices[i] < 0):
            return myExit("Mauvaises valeurs des dés")
    return dices