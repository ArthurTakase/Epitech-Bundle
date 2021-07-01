/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** button
*/

#include "defender.h"

void check_click(sprite_t *sprite, int rect)
{
    sprite->rect.left = rect;
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
}

void check_hover(defender_t *def, sfSprite *sprite, btn_t coords)
{
    if (check_button(def, coords))
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, 150});
    else
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, 255});
}

int check_button(defender_t *defender, btn_t coord)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(defender->window);

    if (mouse.x < coord.x + coord.width && mouse.y < coord.y + coord.height &&
        mouse.x > coord.x && mouse.y > coord.y)
        return 1;
    return 0;
}

void go_to(defender_t *def, int scene)
{
    sfSound_play(def->sounds->click->sound);
    if (scene == EXIT)
        sfRenderWindow_close(def->window);
    else
        def->scene = scene;
}