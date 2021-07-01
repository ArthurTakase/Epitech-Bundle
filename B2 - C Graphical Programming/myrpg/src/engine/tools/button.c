/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** button
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

int is_over(rpg_t *rpg, btn_t coord)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->window);

    if (mouse.x < coord.x + coord.width && mouse.y < coord.y + coord.height &&
        mouse.x > coord.x && mouse.y > coord.y)
        return TRUE;
    return FALSE;
}

sbtn_t *new_button(sfIntRect rect, char *path, sfVector2f pos, sbtn_t *b)
{
    sbtn_t *new = malloc(sizeof(sbtn_t));

    sfVector2f mov = {0, 0};
    new->pos = rect;
    new->s = new_sprite(path, rect, mov, pos);
    new->type = path;
    sfSprite_setScale(new->s->sprite, (sfVector2f){3, 3});
    if (b == NULL)
        new->next = NULL;
    else
        new->next = b;
    return new;
}