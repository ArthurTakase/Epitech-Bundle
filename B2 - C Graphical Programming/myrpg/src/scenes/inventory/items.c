/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** items
*/

#include "rpg.h"

void use_potion(rpg_t *rpg)
{
    if (rpg->player->potion > 0 &&
        rpg->player->life != rpg->player->max_life) {
        rpg->player->life += POTION_HEAL;
        rpg->player->potion -= 1;
        if (rpg->player->life > rpg->player->max_life)
            rpg->player->life = rpg->player->max_life;
        set_txt(rpg->txts->life, rpg->player->life);
        set_txt(rpg->txts->potion, rpg->player->potion);
    }
}

void buy_potion(rpg_t *rpg)
{
    if (rpg->fight != NULL)
        return;
    if (rpg->player->gold >= POTION_PRICE) {
        rpg->player->potion += 1;
        rpg->player->gold -= POTION_PRICE;
        set_txt(rpg->txts->gold, rpg->player->gold);
        set_txt(rpg->txts->potion, rpg->player->potion);
    }
}
