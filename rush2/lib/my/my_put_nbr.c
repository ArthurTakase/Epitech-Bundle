/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** display number argument
*/

int my_putchar(char c);

void my_put_nbr(int nb)
{
    long nb_long = nb;

    if (nb_long > 9) {
        my_put_nbr (nb_long / 10);
    } else if (nb_long < 0) {
        nb_long = -nb_long;
        my_putchar('-');
        my_put_nbr(nb_long / 10);
    }
    my_putchar(nb_long % 10 + 48);
}
