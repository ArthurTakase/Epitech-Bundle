/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** player
*/

#include "struct.h"

void anime_player(run_t *run)
{
    run->player->rect.top += 18;
    if (run->player->rect.top == 144)
        run->player->rect.top = 0;
    sfSprite_setTextureRect(run->player->sprite, run->player->rect);
    sfClock_restart(run->clock->player->clock);
}

void footstep(run_t *run)
{
    sfSound_play(run->sound->footstep->sound);
    sfClock_restart(run->clock->footstep->clock);
}