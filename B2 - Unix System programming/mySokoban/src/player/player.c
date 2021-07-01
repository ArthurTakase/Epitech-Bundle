/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** player
*/

#include "proto.h"
#include <stdlib.h>

void set_player(int x, int y, soko_t *soko)
{
    soko->player = malloc(sizeof(player_t));

    soko->player->x = x;
    soko->player->y = y;
}