/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** alloc
*/

#include <stdlib.h>

char **alloc_laby(int line, int col)
{
    char **laby = malloc(sizeof(char *) * (line + 1));

    if (laby == NULL)
        return NULL;
    for (int i = 0; i < line + 1; i++) {
        laby[i] = malloc(sizeof(char) * (col + 1));
        if (laby[i] == NULL)
            return NULL;
    }
    return laby;
}