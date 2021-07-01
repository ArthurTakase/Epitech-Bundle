/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** delet_sprite
*/

#include "rpg.h"
#include <stdlib.h>

void delet_sprite(sprite_t *spr)
{
    sfSprite_destroy(spr->sprite);
    sfTexture_destroy(spr->texture);
    free(spr);
}