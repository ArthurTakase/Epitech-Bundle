/*
** EPITECH PROJECT, 2020
** tools
** File description:
** tools functions for infinitadd
*/

#include <stdlib.h>
#include "include/my.h"

// Valeur absolue
int abs(int n)
{
    if (n < 0)
        n = -n;
    return n;
}

// Return le numéro de la liste la plus petite
int get_less(char **argv)
{
    int len_un = my_strlen(argv[1]);
    int len_deux = my_strlen(argv[2]);

    if (len_un > len_deux)
        return 2;
    return 1;
}

// Modification du str le plus petit avec ajout de 0 au début
// Return le nouveau str
char *compare_len(char **argv)
{
    int len_un = my_strlen(argv[1]);
    int len_deux = my_strlen(argv[2]);
    int diff = abs(len_un - len_deux);
    int less = get_less(argv);
    char *new = malloc(sizeof(char) * (my_strlen(argv[less]) + diff));

    for (int i = 0; i != diff; i++) {
        new[i] = '0';
    }
    new = my_strcat(new, argv[less]);
    return new;
}
