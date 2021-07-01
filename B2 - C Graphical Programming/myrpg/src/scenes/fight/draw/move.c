/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** move
*/

#include "rpg.h"

void fight_move(rpg_t *rpg)
{
    sprite_t *arr_sprt[7] = {rpg->bg->bg1, rpg->bg->bg1_b, rpg->bg->bg2,
                            rpg->bg->bg2_b, rpg->bg->bg3, rpg->bg->bg3_b,
                            rpg->sprites->mouse};
    sfVector2f new;

    for (int i = 0; i < 7; ++i) {
        new.x = arr_sprt[i]->move.x * rpg->dtime;
        new.y = arr_sprt[i]->move.y * rpg->dtime;
        sfSprite_move(arr_sprt[i]->sprite, new);
    }
}