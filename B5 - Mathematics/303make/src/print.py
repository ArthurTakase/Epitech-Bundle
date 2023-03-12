from typing import Dict, List


def print_result(values: Dict, links: List) -> None:
    print_matrix(values)
    print()
    print_links(links)
    return 0


def print_matrix(values: Dict) -> None:
    ordered_values = sorted(values.keys())
    for value_row in ordered_values:
        print("[", end="")
        for value_column in ordered_values:
            has_link = value_column in values[value_row]
            print(f"{1 if has_link else 0}", end="")
            if value_column != ordered_values[-1]:
                print(" ", end="")
        print("]")


def print_links(links: List[List[str]]) -> None:
    links = sorted(links)
    for dependencies in links:
        if len(dependencies) <= 1:
            continue
        for dependencie in dependencies[:-1]:
            print(dependencie, end=" ")
            print("-> ", end="")
        print(dependencies[-1])
