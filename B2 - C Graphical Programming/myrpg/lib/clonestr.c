/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** clonestr
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