from typing import List, Tuple, Dict


def calculate(tab: List[List[float]], z: int) -> float:
    diqt: Dict[str, List[Tuple[int, int]]] = {
        "20": [(0, 0)],
        "30": [(0, 1), (1, 0)],
        "40": [(0, 2), (1, 1), (2, 0)],
        "50": [(0, 3), (1, 2), (2, 1), (3, 0)],
        "60": [(0, 4), (1, 3), (2, 2), (3, 1), (4, 0)],
        "70": [(2, 3), (3, 2), (4, 1), (1, 4)],
        "80": [(3, 3), (2, 4), (4, 2)],
        "90": [(4, 3), (3, 4)],
        "100": [(4, 4)],
    }
    somme: float = 0.0

    cases: List[Tuple[int, int]] = diqt[str(z)]

    for i in range(len(cases)):
        somme += tab[cases[i][0]][cases[i][1]]
    return somme
