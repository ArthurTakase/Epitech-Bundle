/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_clock
*/

#include "defender.h"
#include <stdlib.h>

clocks_t *init_clock(float limit)
{
    clocks_t *clock = malloc(sizeof(clocks_t));

    clock->clock = sfClock_create();
    clock->limit = limit;
    return clock;
}

void init_all_clock(defender_t *defender)
{
    all_clock_t *clock = malloc(sizeof(all_clock_t));

    clock->dt_game = init_clock(0);
    clock->dt_home = init_clock(0);
    clock->dt_pause = init_clock(0);
    clock->car = init_clock(CAR_TIMER);
    clock->money = init_clock(TIME_MONEY);
    defender->clocks = clock;
}