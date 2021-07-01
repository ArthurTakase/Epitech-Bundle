/*
** EPITECH PROJECT, 2020
** my_find_is_prime
** File description:
** task07
*/

int my_is_prime(int nb)
{
    if (nb == 0 || nb == 1)
        return 0;
    if (nb < 0)
        return 0;
    for (int z = 2; nb > z; z++) {
        if (nb % z == 0)
            return 0;
    }
    return 1;
}
