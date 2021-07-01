/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** tile_remove
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void delete_middle(tile_t *t, int pos)
{
    tile_t *clone = t;
    tile_t *next;

    for (int i = 0; i < pos - 1; i++) {
        clone = clone->next;
    }
    next = clone->next->next;
    delet_sprite(clone->next->s);
    free(clone->next);
    clone->next = next;
}

void delete_first(tile_t **t)
{
    tile_t *tmp = *t;

    *t = (*t)->next;
    delet_sprite(tmp->s);
    free(tmp);
}