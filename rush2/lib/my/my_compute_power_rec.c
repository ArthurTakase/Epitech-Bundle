/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    int temp = nb;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    temp *= my_compute_power_rec(nb, p - 1);
    return temp;
}
