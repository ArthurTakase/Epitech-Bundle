/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** anime
*/

#include "struct.h"

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

void animation(run_t *run)
{
    if (anime(run->clock->player) && run->player->is_jump == 0)
        anime_player(run);
    if (anime(run->clock->footstep) && run->player->is_jump == 0)
        footstep(run);
    if (anime(run->clock->trap))
        anime_trap(run, 0);
    if (anime(run->clock->slime))
        anime_trap(run, 1);
    if (anime(run->clock->bird))
        anime_trap(run, 2);
    if (anime(run->clock->flag))
        anime_trap(run, 3);
    if (anime(run->clock->coin))
        anime_trap(run, 4);
}