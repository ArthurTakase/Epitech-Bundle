/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** cursor
*/

#include "rpg.h"

void move_cursor(rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sprite_t *mouse = rpg->sprites->mouse;

    mouse->pos.x = mouse_pos.x;
    mouse->pos.y = mouse_pos.y;
    sfSprite_setPosition(mouse->sprite, mouse->pos);
    draw_sprite(rpg, mouse);
}

sfVector2i get_mouse(rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);

    return mouse_pos;
}

sfVector2f get_mouse_2f(rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window);
    sfVector2f mouse_convert;

    mouse_convert.x = (float)mouse_pos.x;
    mouse_convert.y = (float)mouse_pos.y;
    return mouse_convert;
}