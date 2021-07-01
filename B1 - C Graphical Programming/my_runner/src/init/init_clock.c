/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** init_clock
*/

#include "struct.h"

clocks_t *init_clock(float limit)
{
    clocks_t *clock = malloc(sizeof(clocks_t));

    clock->clock = sfClock_create();
    clock->limit = limit;
    return clock;
}

void init_all_clock(run_t *run)
{
    all_clock_t *clock = malloc(sizeof(all_clock_t));

    clock->player = init_clock(0.07);
    clock->footstep = init_clock(0.39);
    clock->trap = init_clock(0.1);
    clock->slime = init_clock(0.2);
    clock->bird = init_clock(0.15);
    clock->flag = init_clock(0.3);
    clock->fps = init_clock(1 / 30);
    clock->coin = init_clock(0.005);
    run->clock = clock;
}