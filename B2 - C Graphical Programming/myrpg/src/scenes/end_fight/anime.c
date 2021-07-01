/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** anime
*/

#include "rpg.h"

void anime_end(rpg_t *rpg)
{
    sprite_t *chest = rpg->sprites->chest;

    if (anime(rpg->clocks->player))
        anime_sprite(chest, 180, 1800);
}