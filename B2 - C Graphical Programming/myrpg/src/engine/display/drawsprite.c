/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** drawsprite
*/

#include "rpg.h"

void draw_sprite(rpg_t *rpg, sprite_t *sprite)
{
    sfRenderWindow_drawSprite(rpg->window, sprite->sprite, NULL);
}

void draw_txt(rpg_t *rpg, txt_t *txt)
{
    sfRenderWindow_drawText(rpg->window, txt->txt, NULL);
}