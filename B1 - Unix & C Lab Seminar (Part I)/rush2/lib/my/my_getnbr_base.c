/*
** EPITECH PROJECT, 2020
** my_getnbr_base.c
** File description:
** converts and returns a number in a given base into a decimal.
*/

int len2(char const *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return len;
}

int my_getnbr_base(char *str, char *base)
{
    int b;
    int nb = 0;
    int temp = 1;
    int neg = 1;

    if (str[0] == '-') {
        neg = -neg;
        str = &str[1];
    }
    for (int i = len2(str) - 1; i >= 0; i++) {
        b = 0;
        while (str [i] != base [b])
            b++;
        nb = nb + b * temp;
        temp *= len2(base);
    }
    return nb * neg;
}
