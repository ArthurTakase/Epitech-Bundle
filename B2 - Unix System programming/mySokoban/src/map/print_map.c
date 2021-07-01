/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** print_map
*/

#include "proto.h"
#include <stdlib.h>

int height(int i, soko_t *soko)
{
    return ((LINES + (soko->size->row / 2)) / 2) - (soko->size->row - i);
}

void print_soko(soko_t *soko)
{
    int width = (COLS / 2) - (soko->size->col / 2);

    clear();
    for (int i = 0; soko->map[i] != NULL; i++)
        mvprintw(height(i, soko), width, soko->map[i]);
    refresh();
}