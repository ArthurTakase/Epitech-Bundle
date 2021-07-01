/*
** EPITECH PROJECT, 2020
** my advanced sort word array
** File description:
** my advanced sort word array
*/

#include "include/my.h"
#include <unistd.h>
#include <stddef.h>

int check_swap(char **tab, int i, int (*cmp)(char const *, char const *))
{
    if (i > 0 && cmp(tab[i], tab[i - 1]) < 0)
        return 1;
    return 0;
}

int my_advanced_sort_word_array(char **tab,
                                int (*cmp)(char const *, char const *))
{
    int i = 0;
    char *tmp = NULL;

    while (tab[i] != NULL) {
        if (check_swap(tab, i, cmp) == 1) {
            tmp = my_strdup(tab[i]);
            tab[i] = my_strdup(tab[i - 1]);
            tab[i - 1] = my_strdup(tmp);
            i -= 2;
        }
        i++;
    }
    return 0;
}
