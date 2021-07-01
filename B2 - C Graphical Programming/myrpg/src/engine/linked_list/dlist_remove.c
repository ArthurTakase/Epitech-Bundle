/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** dlist_remove
*/

#include "rpg.h"
#include <stdlib.h>

dlist_t pop_back_dlist(dlist_t li)
{
    dlistnode_t *temp;

    if (is_empty_dlist(li))
        return new_dlist();
    if (li->begin == li->end) {
        free(li);
        return new_dlist();
    }
    temp = li->end;
    li->end = li->end->back;
    li->end->next = NULL;
    temp->next = NULL;
    temp->back = NULL;
    sfSprite_destroy(temp->particle->sprite);
    sfTexture_destroy(temp->particle->texture);
    free(temp);
    li->len -= 1;
    return li;
}

dlist_t pop_front_dlist(dlist_t li)
{
    dlistnode_t *temp;

    if (is_empty_dlist(li))
        return new_dlist();
    if (li->begin == li->end) {
        free(li);
        return new_dlist();
    }
    temp = li->begin;
    li->begin = li->begin->next;
    li->begin->back = NULL;
    temp->next = NULL;
    temp->back = NULL;
    sfSprite_destroy(temp->particle->sprite);
    sfTexture_destroy(temp->particle->texture);
    free(temp);
    li->len -= 1;
    return li;
}

dlist_t clear_dlist(dlist_t li)
{
    while (!is_empty_dlist(li))
        li = pop_back_dlist(li);
    return new_dlist();
}