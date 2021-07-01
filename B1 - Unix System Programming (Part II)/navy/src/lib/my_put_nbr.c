/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** display number argument
*/

#include "struct.h"

int display_nbr(int nb, char n)
{
    if (nb < 0) {
        my_putchar('-');
        n = nb % 10 * -1 + '0';
        display_nbr(nb / -10, n);
        my_putchar(n);
    }
    if (nb > 0) {
        n = nb % 10 + '0';
        display_nbr(nb / 10, n);
        my_putchar(n);
    }
    return 0;
}

int my_put_nbr(int nb)
{
    char n;

    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    display_nbr(nb, n);
    return 1;
}
