/*
** EPITECH PROJECT, 2020
** eval expr
** File description:
** get around
*/

#include "../include/my.h"
#include <stdlib.h>

int is_nbr(char argv)
{
    char compo[5] = {'+', '-', '*', '/', '%'};

    for (int j = 0; j < 5; j++)
        if (argv == compo[j])
            return 0;
    return 1;
}

// Recupère le nombre avant le signe choisit
char *number_before(char *argv, int index)
{
    int flag = 1;
    int j = 0;
    char *un = malloc(sizeof(char) * my_strlen(argv));

    for (int i = index - 1; i >= 0 && is_nbr(argv[i]) == 1; i--) {
        un[j] = argv[i];
        j++;
        if (argv[i - 1] == '-') {
            un[j] = '-';
            flag = 1;
        }
    }
    un[j + flag] = '\0';
    return my_revstr(un);
}

// Récupère le nombre après le signe choisit
char *number_after(char *argv, int index)
{
    int flag = 1;
    int j = 0;
    char *deux = malloc(sizeof(char) * my_strlen(argv));

    if (argv[index + 1] == '-') {
        deux[j] = '-';
        flag = 2;
        j++;
    }
    for (int i = index + flag; argv[i] != '\0' && is_nbr(argv[i]) == 1; i++) {
        deux[j] = argv[i];
        j++;
    }
    deux[j] = '\0';
    return deux;
}
