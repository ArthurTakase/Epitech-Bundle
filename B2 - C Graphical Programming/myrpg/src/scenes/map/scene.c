/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** scene
*/

#include "rpg.h"
#include "lib.h"

void draw_map(rpg_t *rpg, map_t *m)
{
    sfRenderWindow_clear(rpg->window, sfBlack);
    display_map(rpg, m);
    move_cursor(rpg);
}

void map_loop(rpg_t *rpg, map_t *m)
{
    while (m->state == 1) {
        map_event(rpg, m);
        draw_map(rpg, m);
        set_dtime(rpg);
        sfRenderWindow_display(rpg->window);
        sfClock_restart(rpg->clocks->dtime->clock);
    }
}

void map(rpg_t *rpg)
{
    map_t *map = init_map(rpg->tiles, 1);
    map_loop(rpg, map);
}