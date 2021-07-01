/*
** EPITECH PROJECT, 2020
** calcul
** File description:
** handles calculus
*/

#include "../include/my.h"
#include <stdlib.h>

char *calc_add(char *s1, char *s2);

void zero_that(char **str, int nb)
{
    for (int i = 0; i < nb; i++) {
        str[0][i] = '0';
    }
    str[0][nb] = 0;
}

void remove_zero(char **str)
{
    if (str[0][0] != '0')
        return;
    *str = *str + 1;
    remove_zero(str);
}

int max(char *s1, char *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    return (len1 < len2) ? len2 : len1;
}

void calcul(char **results, int len)
{
    my_revstr(results[0]);
    for (int i = 1; i < len; i++) {
        results[i] = calc_add(my_revstr(results[i]), results[i - 1]);
        remove_zero(&results[i]);
    }
    remove_zero(&results[len - 1]);
}

char *mul(char *s1, char *s2)
{
    char **results = malloc(sizeof(char *) * my_strlen(s2));
    int maximum = max(s1, s2);
    int result = 0;

    my_revstr(s1);
    my_revstr(s2);
    for (int i = 0; i < my_strlen(s2); i++)
    {
        results[i] = malloc(sizeof(char) * (maximum + i + 2));
        zero_that(&results[i], maximum + i);
    }
    for (int i = 0; s2[i] != '\0'; i++)
        for (int j = 0; s1[j] != '\0'; j++) {
            result = (s2[i] - 48) * (s1[j] - 48) + (results[i][j + i] - 48);
            results[i][j + i] = (result > 9) ? (result % 10) + 48 : result + 48;
            results[i][j + 1 + i] = (result > 9) ? (result / 10) + 48 : 48;
        }
    calcul(results, my_strlen(s2));
    return results[my_strlen(s2) - 1];
}
