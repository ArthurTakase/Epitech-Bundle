/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** init_background
*/

#include "rpg.h"
#include <stdlib.h>

bg_t *init_background(void)
{
    bg_t *bg = malloc(sizeof(bg_t));

    bg->bg1 = new_sprite("bg/0.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){SPEED1, 0}, (sfVector2f){0, 0});
    bg->bg2 = new_sprite("bg/1.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){SPEED2, 0}, (sfVector2f){0, 0});
    bg->bg3 = new_sprite("bg/2.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){SPEED3, 0}, (sfVector2f){0, 0});
    bg->bg1_b = new_sprite("bg/0.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){SPEED1, 0}, (sfVector2f){960, 0});
    bg->bg2_b = new_sprite("bg/1.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){SPEED2, 0}, (sfVector2f){960, 0});
    bg->bg3_b = new_sprite("bg/2.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){SPEED3, 0}, (sfVector2f){960, 0});
    return bg;
}