from typing import List


def print_vector(vector: List) -> None:
    vector_to_print = [0.0 if round(x, 1) == 0 else round(x, 1) for x in vector]
    print(f"vector result: [{vector_to_print[0]}, {vector_to_print[1]}, {vector_to_print[2]}, {vector_to_print[3]}, {vector_to_print[4]}]")


def print_result(result: List, nb_abscisses: int) -> None:
    for i in range(nb_abscisses):
        print(f"abscissa: {20/( nb_abscisses-1 ) * i:.1f} cm\tradius: {result[i]:.1f} cm")
