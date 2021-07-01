/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** display number argument
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void display_nbr(int nb, char n)
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
}

void my_put_nbr(int nb)
{
    char n = 'a';

    if (nb == 0) {
        my_putchar('0');
        return;
    }
    display_nbr(nb, n);
}
