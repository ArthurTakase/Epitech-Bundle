/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** dtime
*/

#include "rpg.h"

void set_dtime(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->clocks->dtime->clock);

    rpg->dtime = sfTime_asMilliseconds(time);
}