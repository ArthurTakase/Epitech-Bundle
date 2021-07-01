/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** return the factorial of the number
*/

int my_compute_factorial_it(int nb)
{
    int temp = nb;

    if (nb == 0)
        return 1;
    if (nb < 0 || nb > 12)
        return 0;
    for (int i = nb - 1; i != 0; i--)
        temp = temp * i;
    return temp;
}
