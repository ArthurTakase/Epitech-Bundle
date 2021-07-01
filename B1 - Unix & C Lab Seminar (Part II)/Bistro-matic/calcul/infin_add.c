/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** can do infinite addition
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

int marchestp(const char* str);

int check_for_minus(char **str);

void put_to_zero(char *s, int nb);

void choice(int is_1, int is_2, char **tab, char *finale);

void reverse(char **s1, char **s2);

void print_finale(char *finale);

char *remove_zero_deux(char *str);

void sub_check(char **tab, char *r1, char *r2, char *finale);

void adjust_str(char **a, char **b, int nb)
{
    int lena = my_strlen(*a);
    int lenb = my_strlen(*b);
    int diff = 0;
    char *tmp = NULL;

    if (lena < lenb) {
        diff = lenb - lena;
        tmp = malloc(sizeof(char) * (diff + 1 + nb));
        put_to_zero(tmp, diff);
        my_strcat(tmp, *a);
        *a = tmp;
    } else {
        diff = lena - lenb;
        tmp = malloc(sizeof(char) * (diff + 1 + nb));
        put_to_zero(tmp, diff);
        my_strcat(tmp, *b);
        *b = tmp;
    }
}

void substract(char *s1, char *s2, char *dest)
{
    int a = *s1 - 48;
    int b = *s2 - 48;

    if (*s1 == '\0')
        return;
    if (a < b) {
        *dest = ((a + 10) - b) + 48;
        s1[1]--;
        substract(s1 + 1, s2 + 1, dest + 1);
    } else {
        *dest = (a - b) + 48;
        substract(s1 + 1, s2 + 1, dest + 1);
    }
}

void infin_add(char *s1, char *s2, char *dest)
{
    int a;
    int b;
    int r;

    if (*s1 == '\0')
        return;
    a = *s1 - 48;
    b = *s2 - 48;
    r = *dest - 48;
    if (a + b + r >= 10) {
        *dest = ((a + b + r) % 10) + 48;
        dest[1] = '1';
        infin_add(s1 + 1, s2 + 1, dest + 1);
    } else {
        *dest = (a + b + r) + 48;
        infin_add(s1 + 1, s2 + 1, dest + 1);
    }
}

int check_for_substract(char **tab, char *finale, int is_1, int is_2)
{
    char *r1 = my_revstr(my_strdup(tab[0]));
    char *r2 = my_revstr(my_strdup(tab[1]));

    if (is_1 > 0) {
        sub_check(tab, r1, r2, finale);
        return 0;
    }
    if (is_2 > 0) {
        sub_check(tab, r2, r1, finale);
        return 0;
    }
    return 0;
}

char *calc_add(char *s1, char *s2)
{
    int is_1 = check_for_minus(&s1);
    int is_2 = check_for_minus(&s2);
    char *finale = malloc(sizeof(char) * (my_strlen(s1) + 1));
    char *tab[2] = {s1, s2};

    if (!marchestp(tab[0]) || !marchestp(tab[0]))
        return 0;
    if (my_strlen(tab[0]) != my_strlen(tab[1]))
        adjust_str(&tab[0], &tab[1], my_strlen(tab[0]));
    put_to_zero(finale, my_strlen(tab[0]) + 1);
    reverse(&tab[0], &tab[1]);
    choice(is_1, is_2, tab, finale);
    reverse(&tab[0], &tab[1]);
    return remove_zero_deux(my_revstr(finale));
}