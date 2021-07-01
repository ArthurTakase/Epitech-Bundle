/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** cursor
*/

#include "struct.h"

void move_cursor(run_t *run)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(run->window);
    run->cursor->pos.x = mouse_pos.x;
    run->cursor->pos.y = mouse_pos.y;
    sfSprite_setPosition(run->cursor->sprite, run->cursor->pos);
    sfRenderWindow_drawSprite(run->window, run->cursor->sprite, NULL);
}