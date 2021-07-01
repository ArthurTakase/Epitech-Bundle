/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** fade
*/

#include "rpg.h"

int fade_out(rpg_t *rpg)
{
    sfSprite *fade = rpg->fade->fade_out->sprite;

    if (rpg->fade->out >= 254)
        return 1;
    if (anime(rpg->clocks->fade))
        rpg->fade->out += 5;
    sfSprite_setColor(fade, (sfColor){255, 255, 255, rpg->fade->out});
    draw_sprite(rpg, rpg->fade->fade_out);
    return 0;
}

int fade_in(rpg_t *rpg)
{
    sfSprite *fade = rpg->fade->fade_in->sprite;

    if (rpg->fade->in <= 1)
        return 1;
    if (anime(rpg->clocks->fade))
        rpg->fade->in -= 5;
    sfSprite_setColor(fade, (sfColor){255, 255, 255, rpg->fade->in});
    draw_sprite(rpg, rpg->fade->fade_in);
    return 0;
}

int circle_animation(rpg_t *rpg)
{
    sfSprite *circle = rpg->fade->circle->sprite;

    if (rpg->fade->circle_fade <= 1)
        return 1;
    if (anime(rpg->clocks->fade))
        rpg->fade->circle_fade -= 0.1;
    sfSprite_setScale(circle,
                (sfVector2f){rpg->fade->circle_fade, rpg->fade->circle_fade});
    return 0;
}