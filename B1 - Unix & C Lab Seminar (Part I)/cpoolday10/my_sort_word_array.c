/*
** EPITECH PROJECT, 2020
** my sort word array
** File description:
** my sort word array
*/

#include "include/my.h"
#include <unistd.h>
#include <stddef.h>

int check_swap(char **tab, int i)
{
    int k = 0;

    if (i > 0 && tab[i][k] < tab[i - 1][k])
        return 1;
    else if (i > 0 && tab[i][k] == tab[i - 1][k]) {
        while (tab[i][k] == tab[i - 1][k])
            k++;
        if (tab[i][k] < tab[i - 1][k])
            return 1;
        else
            return 0;
    } else
        return 0;
}

int my_sort_word_array(char **tab)
{
    int i = 0;
    char *tmp = NULL;

    while (tab[i] != NULL) {
        if (check_swap(tab, i) == 1) {
            tmp = my_strdup(tab[i]);
            tab[i] = my_strdup(tab[i - 1]);
            tab[i - 1] = my_strdup(tmp);
            i -= 2;
        }
        i++;
    }
    return 0;
}
