/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** anime
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

int anime(clocks_t *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock->clock);
    if (sfTime_asSeconds(time) > clock->limit) {
        sfClock_restart(clock->clock);
        return 1;
    }
    return 0;
}

void animation(defender_t *def)
{
    waves_t *wave = def->waves;
    if (wave->ennemies != wave->spawned && anime(def->clocks->car)) {
        def->trap = push_back_list(def->trap,
            new_sprite("car.png", (sfIntRect) {0, 0, 32, 26},
                    (sfVector2f) {MOVE1, MOVE2}, (sfVector2f) {265, 271}));
        wave->spawned += 1;
    }
    if (anime(def->clocks->money) && def->waves->alive != 0)
        set_money(def, TIME_REWARD);
}
