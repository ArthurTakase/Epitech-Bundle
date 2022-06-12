from json import load
from typing import List, Dict, Any


def load_json(file: str) -> Any:
    with open(file, "r") as f:
        return load(f)


def extract_keys(file: str) -> List[Any]:
    data = load_json(file)
    return list(data.keys())


def to_int_array(arr: List[Any]) -> List[int]:
    res: List[int] = []
    try:
        res = [int(elem) for elem in arr]
    except ValueError:
        print("a data in the dataset isn't an integer")
        exit(84)
    return res
