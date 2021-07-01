/*
** EPITECH PROJECT, 2020
** script
** File description:
** additional function
*/

#include "../include/my.h"

int check_for_substract(char **tab, char *finale, int is_1, int is_2);

void infin_add(char *s1, char *s2, char *dest);

void substract(char *s1, char *s2, char *dest);

int marchestp(const char* str)
{
    if (*str == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 48 && str[i] <= 57) || str[i] == 45))
            return 0;
    }
    return 1;
}

int check_for_minus(char **str)
{
    int count = 0;
    char *tmp = *str;

    while (tmp[count] == '-') {
        count++;
    }
    *str = *str + count;
    return count;
}

void put_to_zero(char *s, int nb)
{
    for (int i = 0; i < nb; i++) {
        s[i] = '0';
    }
    s[nb] =  '\0';
}

void choice(int is_1, int is_2, char **tab, char *finale)
{
    if (is_1 == 0 && is_2 == 0)
	    infin_add(tab[0], tab[1], finale);
    else if (is_1 && is_2) {
        my_putchar('-');
        infin_add(tab[0], tab[1], finale);
    } else {
        check_for_substract(tab, finale, is_1, is_2);
    }
}

void sub_check(char **tab, char *r1, char *r2, char *finale)
{
    if (my_strcmp(r1, r2) < 0)
        substract(tab[1], tab[0], finale);
    else {
        if (my_strcmp(tab[0], tab[1]) == 0)
            my_putchar('0');
        substract(tab[0], tab[1], finale);
    }
}