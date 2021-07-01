/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** end
*/

#include "proto.h"

int victory(soko_t *soko)
{
    for (int i = 0; soko->end_x[i] != -1; i++) {
        if (soko->map[soko->end_y[i]][soko->end_x[i]] != 'X')
            return NO_VICTORY;
    }
    soko->end_value = 0;
    return VICTORY;
}

int is_wall(char elem)
{
    if (elem == '#' || elem == 'X')
        return 1;
    return 0;
}

int check_around(soko_t *soko, int x, int y)
{
    if (is_wall(soko->map[y - 1][x]) && is_wall(soko->map[y][x - 1]))
        return 1;
    if (is_wall(soko->map[y][x - 1]) && is_wall(soko->map[y + 1][x]))
        return 1;
    if (is_wall(soko->map[y + 1][x]) && is_wall(soko->map[y][x + 1]))
        return 1;
    if (is_wall(soko->map[y][x + 1]) && is_wall(soko->map[y - 1][x]))
        return 1;
    return 0;
}

int defeat(soko_t *soko)
{
    int bad_box = 0;

    for (int y = 0; y != soko->size->row; y++)
        for (int x = 0; x != soko->size->col; x++)
            if (soko->map[y][x] == 'X')
                if (check_around(soko, x, y))
                    bad_box++;
    if (bad_box == soko->nb_box) {
        soko->end_value = 1;
        return DEFEAT;
    }
    return NO_VICTORY;
}