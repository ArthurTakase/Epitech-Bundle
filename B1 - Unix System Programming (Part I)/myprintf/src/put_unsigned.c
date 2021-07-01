/*
** EPITECH PROJECT, 2020
** My_Printf
** File description:
** put_unsigned
*/

int my_putchar(char c);

void display_unsigned(unsigned int nb, char n)
{
    if (nb < 0) {
        my_putchar('-');
        n = nb % 10 * -1 + '0';
        display_unsigned(nb / -10, n);
        my_putchar(n);
    }
    if (nb > 0) {
        n = nb % 10 + '0';
        display_unsigned(nb / 10, n);
        my_putchar(n);
    }
}

int put_unsigned(unsigned int nb)
{
    char n;

    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    display_unsigned(nb, n);
    return 1;
}