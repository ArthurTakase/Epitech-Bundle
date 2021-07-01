/*
** EPITECH PROJECT, 2020
** modulo
** File description:
** unlimited one
*/

#include "../include/my.h"
#include <stdlib.h>

void remove_zero(char **);

char *calc_add(char *s1, char *s2);

void zero_that(char **str, int n);

char *remove_zero_deux(char *str);

void turn_to_neg(char **str);

int tell_sup(char *s1, char *s2);

char *pow_str(char *str, int n);

void calc_mod(int diff, char **tab)
{
    char *nbr = pow_str(tab[1], diff);

    remove_zero(&tab[3]);
    if (tell_sup(tab[0], remove_zero_deux(calc_add(tab[3], nbr))) == 2) {
        if (diff - 1 == -1)
            return;
        calc_mod(diff - 1, tab);
    }
    else {
        tab[2] = calc_add(tab[2], pow_str("1", diff));
        tab[3] = calc_add(tab[3], nbr);
        calc_mod(diff, tab);
    }
}

char *modulo(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    int diff = len1 - len2;
    char *finale = malloc(sizeof(char) * len1);
    char *calc = malloc(sizeof(char) * len1);
    char *args[4] = {s1, s2, calc, finale};

    if (diff < 0)
        return "0";
    zero_that(&finale, len1);
    zero_that(&calc, len1);
    calc_mod(diff, args);
    turn_to_neg(&args[3]);
    return remove_zero_deux(calc_add(args[3], s1));
}