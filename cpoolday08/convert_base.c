/*
** EPITECH PROJECT, 2020
** convert_base.c
** File description:
** convert nbr in base to an other base and put in char *
*/

#include <stdlib.h>

char *my_revstr(char *str);

int my_strlen(char const *str);

char *convert_dec(int nbr, char *base_to)
{
    int base = my_strlen(base_to);
    char  *result = malloc(sizeof(char) * 1000);

    for (int i = 0; nbr != 0; i++) {
        if ((nbr % base) < 10) {
            result[i] = (nbr % base) + 48;
        } else {
            result[i] = (nbr % base) + 55;
        }
        nbr /= base;
    }
    my_revstr(result);
    return result;
}

char *convert_base(char *nbr, char *base_from, char *base_to)
{
    int power = 1;
    int nb = 0;
    int total = 0;
    int base = my_strlen(base_from);
    char *result;

    for (int i = my_strlen(nbr) - 1; i >= 0; i--) {
        if (nbr[i] < 58  && nbr[i] > 47)
            nb = nbr[i] - 48;
        else
            nb = nbr[i] - 55;
        nb = nb * power;
        total += nb;
        power *= base;
    }
    result = convert_dec(total, base_to);
    return result;
}
