/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** drawsprite
*/

#include "defender.h"

void draw_sprite(defender_t *def, sprite_t *sprite)
{
    sfRenderWindow_drawSprite(def->window, sprite->sprite, NULL);
}