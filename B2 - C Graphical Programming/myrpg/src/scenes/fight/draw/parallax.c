/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** parallax
*/

#include "rpg.h"

void draw_parallax(rpg_t *rpg)
{
    sprite_t *arr_bg[6] = {rpg->bg->bg1, rpg->bg->bg1_b, rpg->bg->bg2,
                            rpg->bg->bg2_b, rpg->bg->bg3, rpg->bg->bg3_b};

    for (int i = 0; i < 6; ++i)
        draw_sprite(rpg, arr_bg[i]);
}

void set_parallax(rpg_t *rpg)
{
    int arr_mv[3] = {SPEED1, SPEED2, SPEED3};
    sprite_t *arr_bg[3] = {rpg->bg->bg1, rpg->bg->bg2, rpg->bg->bg3};
    sprite_t *arr_bg2[3] = {rpg->bg->bg1_b, rpg->bg->bg2_b, rpg->bg->bg3_b};

    for (int i = 0; i < 3; ++i)
        if (sfSprite_getPosition(arr_bg[i]->sprite).x + arr_mv[i] < -960)
            sfSprite_setPosition(arr_bg[i]->sprite, arr_bg[i]->pos);
    for (int i = 0; i < 3; ++i)
        if (sfSprite_getPosition(arr_bg2[i]->sprite).x + arr_mv[i] < 0)
            sfSprite_setPosition(arr_bg2[i]->sprite, arr_bg2[i]->pos);
}