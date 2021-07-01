/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** scene
*/

#include "rpg.h"
#include "lib.h"

void fight(rpg_t *rpg)
{
    fight_draw(rpg);
    fade_in(rpg);
    if (rpg->fight->turn == PLAYER)
        fight_event(rpg);
    else
        ennemis_event(rpg);
    set_parallax(rpg);
    set_dtime(rpg);
    fight_move(rpg);
    animation(rpg);
    fight_end(rpg);
    sfClock_restart(rpg->clocks->dtime->clock);
    sfRenderWindow_display(rpg->window);
}