/*
** EPITECH PROJECT, 2020
** my_compute_factorial_rec
** File description:
** task02
*/

int my_compute_factorial_rec(int nb)
{
    int result;

    if (nb == 0)
        return 1;
    if (nb < 0 || nb > 12)
        return 0;
    result = nb * my_compute_factorial_rec(nb - 1);
    return result;
}
