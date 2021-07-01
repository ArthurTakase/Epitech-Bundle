/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert nbr with a given base
*/

void my_putchar(char c);

int len(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return len;
}

int my_putnbr_base(int nbr, char const *base)
{
    int len_base = len(base);

    if (nbr < 0) {
        nbr = -nbr;
        my_putchar('-');
    }
    if (nbr == 0) {
        return (0);
    } else {
        my_putnbr_base(nbr / len_base, base);
    }
    my_putchar(base[nbr % len_base]);
    return 0;
}
