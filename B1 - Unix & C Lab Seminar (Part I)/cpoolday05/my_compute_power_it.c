/*
** EPITECH PROJECT, 2020
** my_compute_power_it
** File description:
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    for (p; p > 1; p--)
        result *= nb;
    return result;
}
