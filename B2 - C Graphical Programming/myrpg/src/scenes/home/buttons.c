/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** buttons
*/

#include "rpg.h"

int get_buttons_home(rpg_t *rpg)
{
    sprite_t *arr_bt[3] = {rpg->menu->play, rpg->menu->param, rpg->menu->exit};
    sfFloatRect mouse;
    sfFloatRect btn;

    for (int i = 0; i != 3; i++) {
        mouse = sfSprite_getGlobalBounds(rpg->sprites->mouse->sprite);
        btn = sfSprite_getGlobalBounds(arr_bt[i]->sprite);
        if (sfFloatRect_intersects(&mouse, &btn, NULL))
            return i;
    }
    return -1;
}