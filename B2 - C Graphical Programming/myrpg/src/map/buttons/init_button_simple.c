/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** init_button_simple
*/

#include "rpg.h"
#include <stdlib.h>

button_t *init_simple_button(sfVector2f pos, char *path)
{
    button_t *new = malloc(sizeof(button_t));
    sfIntRect rect = {0, 0, 512, 512};
    sfVector2f move = {0, 0};

    new->s = new_sprite(path, rect, move, pos);
    sfSprite_setScale(new->s->sprite, (sfVector2f){0.125, 0.125});
    return new;
}