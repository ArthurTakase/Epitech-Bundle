/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert nbr with a given base
*/

void my_putchar(char c);

int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int len_base = my_strlen(base);

    if (nbr < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    if (nbr == 0)
        return 0;
    else
        my_putnbr_base(nbr / len_base, base);
    my_putchar(base[nbr % len_base]);
    return 0;
}
