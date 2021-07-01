/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** clone_map
*/

#include <stdlib.h>
#include "lib.h"

char *clonestr(char *txt)
{
    char *clone;
    int i = 0;

    if (txt == NULL)
        return NULL;
    clone = malloc(sizeof(char) * (my_strlen(txt) + 1));
    for (; txt[i] != '\0'; i++)
        clone[i] = txt[i];
    clone[i] = '\0';
    return clone;
}

int len_array(char **array)
{
    int i = 0;

    while (*array) {
        i++;
        array++;
    }
    return i;
}

char **clone_2d(char **src)
{
    int len = len_array(src);
    char **new = malloc(sizeof(char *) * (len + 1));
    int i;

    for (i = 0; i != len; i++)
        new[i] = clonestr(src[i]);
    new[i] = NULL;
    return new;
}