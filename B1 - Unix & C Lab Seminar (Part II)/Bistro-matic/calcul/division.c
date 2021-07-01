/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** can do infinite addition
*/

#include "../include/my.h"
#include <stdlib.h>

void remove_zero(char **);

char *calc_add(char *s1, char *s2);

void zero_that(char **str, int n);

char *remove_zero_deux(char *str);

int tell_sup(char *s1, char *s2);

char *pow_str(char *str, int n)
{
    char *zero = malloc(n);
    char *finale = malloc(my_strlen(str) + n + 1);

    zero_that(&zero, n);
    my_strcat(finale, str);
    my_strcat(finale, zero);
    free(zero);
    return finale;
}

void calc_div(char *finale, int diff, char **tab)
{
    char *nbr = pow_str(tab[1], diff);

    remove_zero(&finale);
    if (tell_sup(tab[0], remove_zero_deux(calc_add(finale, nbr))) == 2) {
        if (diff - 1 == -1)
            return;
        calc_div(finale, diff - 1, tab);
    }
    else {
        tab[2] = calc_add(tab[2], pow_str("1", diff));
        finale = calc_add(finale, nbr);
        calc_div(finale, diff, tab);
    }
}

char *divide(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int diff = len1 - len2;
    char *finale = malloc(sizeof(char) * len1);
    char *calc = malloc(sizeof(char) * len1);
    char *args[3] = {s1, s2, calc};

    if (diff < 0)
        return "0";
    zero_that(&finale, len1);
    zero_that(&calc, len1);
    calc_div(finale, diff, args);
    free(finale);
    return remove_zero_deux(args[2]);
}