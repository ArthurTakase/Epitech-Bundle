/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** can do infinite addition
*/

#include "../include/my.h"
#include <stdlib.h>

void reverse(char **s1, char **s2)
{
    my_revstr(*s1);
    my_revstr(*s2);
}

void print_finale(char *finale)
{
    my_revstr(finale);
    while (*finale == '0')
        finale++;
    my_putstr(finale);
}

char *remove_zero_deux(char *str)
{
    char *finale = malloc(my_strlen(str));
    int count = 0;

    while (str[count] == '0')
        count++;
    my_strcat(finale, str + count);
}

int tell_sup(char *s1, char *s2)
{
    if (my_strlen(s1) < my_strlen(s2))
        return 2;
    else if (my_strlen(s1) > my_strlen(s2))
        return 1;
    if (*s1 < *s2)
        return 2;
    else if (*s1 > *s2)
        return 1;
    else
        tell_sup(s1 + 1, s2 + 1);
}

void turn_to_neg(char **str)
{
    char *finale = malloc(my_strlen(*str) + 1);

    my_revstr(*str);
    my_strncat(finale, *str, my_strlen(*str));
    finale[my_strlen(*str)] = '-';
    my_revstr(finale);
    *str = finale;
}
