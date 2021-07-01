/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** player
*/

#include "proto.h"
#include "lib.h"
#include <stdlib.h>

int check_coll(int x, int y, soko_t *soko)
{
    int temp_x = soko->player->x + x;
    int temp_y = soko->player->y + y;

    if (temp_y <= 0 || temp_x <= 0 || temp_y >= soko->size->row
        || temp_x >= soko->size->col)
        return 0;
    if (soko->map[temp_y][temp_x] == '#')
        return 0;
    switch (is_box_good(soko, x, y)) {
        case BLOCK_BOX:
            return 0;
        case NO_BOX:
            break;
        case MOVE_BOX:
            move_box(soko, x, y);
            return 1;
    }
    return 1;
}

int move_player(int key, soko_t *soko)
{
    if (key == 65)
        up(soko);
    if (key == 66)
        down(soko);
    if (key == 67)
        left(soko);
    if (key == 68)
        right(soko);
    if (key == 32)
        new_sokoban(soko);
    if (key == 0)
        soko->map[soko->player->y][soko->player->x] = 'P';
    return 0;
}