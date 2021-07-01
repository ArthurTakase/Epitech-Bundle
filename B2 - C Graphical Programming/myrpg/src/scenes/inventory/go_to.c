/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** go_to
*/

#include "rpg.h"

void go_to_inventory(rpg_t *rpg)
{
    set_txt(rpg->txts->potion, rpg->player->potion);
    set_txt(rpg->txts->key, rpg->player->key);
    set_txt(rpg->txts->lvl, rpg->player->xp);
    set_txt(rpg->txts->max_life, rpg->player->max_life);
    set_txt(rpg->txts->att, rpg->player->att);
    set_txt(rpg->txts->gold, rpg->player->gold);
    set_txt(rpg->txts->life, rpg->player->life);
    rpg->scene = INVENTORY;
}