/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** init_fade
*/

#include "rpg.h"
#include <stdlib.h>

fade_t *init_fade(void)
{
    fade_t *f = malloc(sizeof(fade_t));

    f->fade_in = new_sprite("black.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    f->fade_out = new_sprite("black.png", (sfIntRect){0, 0, 960, 540},
                    (sfVector2f){0, 0}, (sfVector2f){0, 0});
    f->circle = new_sprite("circle.png", (sfIntRect){0, 0, 1920, 1080},
                        (sfVector2f){0, 0}, (sfVector2f){740, 460});
    f->in = 255;
    f->out = 0;
    f->circle_fade = 10;
    return f;
}