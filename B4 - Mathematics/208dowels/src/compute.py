from typing import List


def get_chi_squared(Ox: List[int], Tx: List[float]) -> float:
    res: List[float] = []
    for o, t in zip(Ox, Tx):
        res.append((o - t) ** 2 / t)
    return sum(res)
