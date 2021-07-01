/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** scene
*/

#include "rpg.h"

void inventory(rpg_t *rpg)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    draw_sprite(rpg, rpg->sprites->inventory);
    draw_txt(rpg, rpg->txts->att);
    draw_txt(rpg, rpg->txts->gold);
    draw_txt(rpg, rpg->txts->key);
    draw_txt(rpg, rpg->txts->lvl);
    draw_txt(rpg, rpg->txts->life);
    draw_txt(rpg, rpg->txts->slash);
    draw_txt(rpg, rpg->txts->max_life);
    draw_txt(rpg, rpg->txts->potion);
    inventory_event(rpg);
    set_dtime(rpg);
    move_cursor(rpg);
    sfClock_restart(rpg->clocks->dtime->clock);
    sfRenderWindow_display(rpg->window);
}