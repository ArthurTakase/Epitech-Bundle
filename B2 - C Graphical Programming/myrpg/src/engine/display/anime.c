/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** anime
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

int anime(clocks_t *clock)
{
    sfTime time;

    time = sfClock_getElapsedTime(clock->clock);
    if (sfTime_asSeconds(time) > clock->limit) {
        sfClock_restart(clock->clock);
        return TRUE;
    }
    return FALSE;
}

int anime_sprite(sprite_t *sprite, int step, int limit)
{
    int return_value = 0;

    sprite->rect.left += step;
    if (sprite->rect.left >= limit) {
        sprite->rect.left = 0;
        return_value = 1;
    }
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return return_value;

}

void animation(rpg_t *rpg)
{
    if (anime(rpg->clocks->player)) {
        anime_player(rpg);
        if (rpg->fight != NULL)
            anime_ennemis(rpg);
        if (rpg->sprites->punch->state == 0 &&
            anime_sprite(rpg->sprites->punch, 64, 128))
            rpg->sprites->punch->state = 1;
        if (rpg->sprites->slash->state == 0 &&
            anime_sprite(rpg->sprites->slash, 64, 128))
            rpg->sprites->slash->state = 1;
    }
    if (anime(rpg->clocks->reset_rand))
        randomize();
}
