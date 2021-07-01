/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** gamelopp
*/

#include "defender.h"
#include "lib.h"

void restart_other_clock(defender_t *def)
{
    clocks_t *arr_clock[6] = {def->clocks->dt_home, def->clocks->dt_game,
                            def->clocks->dt_pause, def->clocks->dt_game,
                            def->clocks->dt_home, def->clocks->dt_home};

    for (int i = 0; i < 6; ++i) {
        if (i != def->scene)
            sfClock_restart(arr_clock[i]->clock);
    }
}

int gameloop(defender_t *defender)
{
    int scene[7] = {HOME, GAME, PAUSE, TOWER, SETTINGS, HOW, END};
    void (*scene_display[7])(defender_t *) = {home, game, s_pause, tower,
                                            settings, how, end};

    while (sfRenderWindow_isOpen(defender->window)) {
        for (int i = 0; i != 8; i++)
            if (defender->scene == scene[i])
                scene_display[i](defender);
    }
    destroy(defender);
    sfRenderWindow_destroy(defender->window);
    return 0;
}