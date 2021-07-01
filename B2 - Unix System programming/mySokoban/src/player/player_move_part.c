/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** player_move_part
*/

#include "proto.h"

void up(soko_t *soko)
{
    int x = soko->player->x;
    int y;

    if (soko->player->y > 0 && check_coll(0, -1, soko))
        soko->player->y -= 1;
    y = soko->player->y;
    soko->map[y][x] = 'P';
    soko->map[y + 1][x] = soko->map_save[y + 1][x];
}

void down(soko_t *soko)
{
    int x = soko->player->x;
    int y;

    if (soko->player->y < soko->size->row - 1 && check_coll(0, 1, soko))
        soko->player->y += 1;
    y = soko->player->y;
    soko->map[y][x] = 'P';
    soko->map[y - 1][x] = soko->map_save[y - 1][x];
}

void left(soko_t *soko)
{
    int x;
    int y = soko->player->y;

    if (soko->player->x < soko->size->col - 1  && check_coll(1, 0, soko))
        soko->player->x += 1;
    x = soko->player->x;
    soko->map[y][x] = 'P';
    soko->map[y][x - 1] = soko->map_save[y][x - 1];
}

void right(soko_t *soko)
{
    int x;
    int y = soko->player->y;

    if (soko->player->x > 0 && check_coll(-1, 0, soko))
        soko->player->x -= 1;
    x = soko->player->x;
    soko->map[y][x] = 'P';
    soko->map[y][x + 1] = soko->map_save[y][x + 1];
}