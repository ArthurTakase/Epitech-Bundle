/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** box
*/

#include "proto.h"
#include "lib.h"

void move_box(soko_t *soko, int x, int y)
{
    int new_y = soko->player->y + y + y;
    int new_x = soko->player->x + x + x;

    soko->map[new_y][new_x] = 'X';
    if (soko->map_save[new_y - y][new_x - x] == 'X')
        soko->map_save[new_y - y][new_x - x] = ' ';
    soko->map[new_y - y][new_x - x] = soko->map_save[new_y - y][new_x - x];
}

int is_box_good(soko_t *soko, int x, int y)
{
    int new_y = soko->player->y + y;
    int new_x = soko->player->x + x;

    if (soko->map[new_y][new_x] == 'X') {
        if (soko->map[new_y + y][new_x + x] == '#')
            return BLOCK_BOX;
        else if (soko->map[new_y + y][new_x + x] == 'X')
            return BLOCK_BOX;
        else
            return MOVE_BOX;
    }
    return NO_BOX;
}