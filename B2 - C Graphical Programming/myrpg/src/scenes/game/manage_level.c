/*
** EPITECH PROJECT, 2021
** manage_level.c
** File description:
** manage_level
*/

#include "lib.h"
#include "rpg.h"

void manage_level(rpg_t *rpg)
{
    if (rpg->player->xp >= rpg->player_map->nxt_lvl) {
        rpg->player->lvl += 1;
        rpg->player_map->nxt_lvl = 1.5 * rpg->player->xp + 50;
        if (my_strcmp(THIRD_MAP, rpg->current_map) == 0)
            switch_map(rpg, SECOND_MAP);
        else
            switch_map(rpg, THIRD_MAP);
    }
}