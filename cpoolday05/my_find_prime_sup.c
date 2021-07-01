/*
** EPITECH PROJECT, 2020
** my_find_is_prime
** File description:
** task07
*/

int my_is_prime(int nb);

int my_find_prime_sup (int nb)
{
    int temp = nb;

    if (my_is_prime(nb) == 1) {
        return nb;
    }
    while (my_is_prime(temp) == 0) {
        temp++;
    }
    return temp;
}
