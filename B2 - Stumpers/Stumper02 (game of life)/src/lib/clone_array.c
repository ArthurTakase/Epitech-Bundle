/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-stumper2-arthur.decaen
** File description:
** clone_array
*/

#include "gameoflife.h"
#include "lib.h"
#include <string.h>

char *clonestr(char *txt)
{
    char *clone;
    int i = 0;

    if (txt == NULL)
        return NULL;
    clone = malloc(sizeof(char) * (strlen(txt) + 1));
    if (clone == NULL)
        exit(84);
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

char **clone_array(char **src)
{
    int len = len_array(src);
    char **new = malloc(sizeof(char *) * (len + 1));
    int i;

    if (new == NULL)
        exit(84);
    for (i = 0; i != len; i++)
        new[i] = clonestr(src[i]);
    new[i] = NULL;
    return new;
}

