/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_clock
*/

#include "rpg.h"
#include <stdlib.h>

clocks_t *new_clock(float limit)
{
    clocks_t *clock = malloc(sizeof(clocks_t));

    clock->clock = sfClock_create();
    clock->limit = limit;
    return clock;
}

all_clock_t *init_all_clock(void)
{
    all_clock_t *clocks = malloc(sizeof(all_clock_t));

    clocks->dtime = new_clock(0);
    clocks->player = new_clock(0.18);
    clocks->player_map = new_clock(0.15);
    clocks->particule = new_clock(0.05);
    clocks->ennemi = new_clock(0.5);
    clocks->fade = new_clock(0.001);
    clocks->reset_rand = new_clock(10);
    return clocks;
}