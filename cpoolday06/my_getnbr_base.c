/*
** EPITECH PROJECT, 2020
** my_getnbr_base.c
** File description:
** returns a number in a given base into a decimal.
*/

int my_strlen(char const *str);

int my_getnbr_base(char *str, char *base)
{
    int b;
    int nb = 0;
    int temp = 1;
    int neg = 1;

    if (str[0] == '-')
    {
        neg = -neg;
        str = &str[1];
    }
    for (int i = my_strlen(str) - 1; i >= 0; i++)
    {
        b = 0;
        while (str [i] != base [b])
            b++;
        nb = nb + b * temp;
        temp *= my_strlen(base);
    }
    return (nb * neg);
}
