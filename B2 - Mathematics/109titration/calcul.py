#!/usr/bin/env python3
from typing import List

PH = 1
VOL = 0


def division(arg1: float, arg2: float) -> float:
    if arg2 == 0:
        print("Error: division par 0")
        exit(84)
    else:
        return arg1 / arg2


def derivate(
    vol: float,
    vol_before: float,
    vol_after: float,
    ph: float,
    ph_before: float,
    ph_after: float,
) -> float:
    left: float = division(ph - ph_before, vol - vol_before)
    right: float = division(ph_after - ph, vol_after - vol)
    derivative: float = left * division(vol_after - vol, vol_after - vol_before)
    derivative += right * division(vol - vol_before, vol_after - vol_before)
    return derivative


def find_equivalence_by_zero(args: List[List[float]]) -> None:
    for i in range(len(args[PH])):
        args[PH][i] = abs(args[PH][i])

    equivalence_ph: float = min(args[PH])
    equivalence_ml: float = args[VOL][args[PH].index(equivalence_ph)]

    print(f"\nEquivalence point at {equivalence_ml:.1f} ml")


def find_equivalence(args: List[List[float]]) -> float:
    equivalence_ph: float = 0
    equivalence_ml: float = 0

    for i in range(1, len(args) - 1):
        if equivalence_ph < args[i - 1][PH]:
            equivalence_ph = args[i - 1][PH]
            equivalence_ml = args[i - 1][VOL]

    print(f"\nEquivalence point at {equivalence_ml:.1f} ml")
    return equivalence_ml


def derivate_part(args: List[List[float]], limit: int) -> None:
    for i in range(1, len(args) - limit):
        derive: float = derivate(
            args[i][VOL],
            args[i - 1][VOL],
            args[i + 1][VOL],
            args[i][PH],
            args[i - 1][PH],
            args[i + 1][PH],
        )
        print(f"{args[i][VOL]:.1f} ml -> {derive:.2f}")
        # Modification de args pour la prochaine dérivée
        args[i - 1][VOL] = args[i][VOL]
        args[i - 1][PH] = derive


def estimate(
    current: float, vol_a: float, vol_b: float, ph_a: float, ph_b: float
) -> float:
    return ph_a + (current - vol_a) * division(ph_b - ph_a, vol_b - vol_a)


def estimated_derivative(
    args: List[List[float]], first_eq_value: float
) -> List[List[float]]:
    # Récupération de l'emplacement de la première équivalence dans la nouvelle liste
    origin: int = 0
    for i in range(len(args)):
        if args[i][VOL] == first_eq_value:
            origin = i

    # Calcul Dérivée estimée
    step: float = 0.1
    current: float = args[origin - 1][VOL]
    end: float = args[origin + 1][VOL]

    # Création d'une liste pour stocker les resultats
    result: List[List[float]] = [[], []]
    i: int = 0

    while current <= end:
        result[VOL].append(current)
        if current < args[origin][VOL]:
            result[PH].append(
                estimate(
                    current,
                    args[origin - 1][VOL],
                    args[origin][VOL],
                    args[origin - 1][PH],
                    args[origin][PH],
                )
            )
        else:
            result[PH].append(
                estimate(
                    current,
                    args[origin][VOL],
                    args[origin + 1][VOL],
                    args[origin][PH],
                    args[origin + 1][PH],
                )
            )
        print(f"{result[VOL][i]:.1f} ml -> {result[PH][i]:.2f}")
        current += step
        i += 1
    return result
