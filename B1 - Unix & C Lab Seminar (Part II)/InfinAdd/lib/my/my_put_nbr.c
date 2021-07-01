/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** display number argument
*/

int my_putchar(char c);

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
}

int my_put_nbr(int nb)
{
    char n;

    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    display_nbr(nb, n);
}
