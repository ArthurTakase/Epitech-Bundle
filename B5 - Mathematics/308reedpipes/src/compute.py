from typing import List, Dict


def compute_vector(var: Dict) -> List:
    vector: List = [0.0, None, None, None, 0.0]

    A = 6 * (var["r10"] - 2 * var["r5"] + var["r0"]) / 50
    B = 6 * (var["r15"] - 2 * var["r10"] + var["r5"]) / 50
    C = 6 * (var["r20"] - 2 * var["r15"] + var["r10"]) / 50
    vector[2] = (B - (A + C) / 4) * 4 / 7
    vector[1] = A / 2 - 0.25 * vector[2]
    vector[3] = C / 2 - 0.25 * vector[2]
    return vector


def compute_splines(vector: List, constraints: List, abscisses: List[float], nb_abscisses: int) -> List[float]:
    results: List[float] = []
    for abscisse in range(int(nb_abscisses)):
        X = 20 / (nb_abscisses - 1) * abscisse
        i = int((X - 0.01) / 5) + 1
        result = (
            -vector[i - 1] / 30 * pow(X - abscisses[i], 3)
            + vector[i] / 30 * pow(X - abscisses[i - 1], 3)
            - (constraints[i - 1] / 5 - 5 / 6 * vector[i - 1]) * (X - abscisses[i])
            + (constraints[i] / 5 - 5 / 6 * vector[i]) * (X - abscisses[i - 1])
        )
        results.append(result)

    return results
