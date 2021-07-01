/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** dlist_add
*/

#include "rpg.h"
#include <stdlib.h>

dlist_t push_back_dlist(dlist_t li, sprite_t *x)
{
    dlistnode_t *element = malloc(sizeof(dlistnode_t));

    element->particle = x;
    element->next = NULL;
    element->back = NULL;
    if (is_empty_dlist(li)) {
        li = malloc(sizeof(dlist_t));
        li->len = 0;
        li->begin = element;
        li->end = element;
    } else {
        li->end->next = element;
        element->back = li->end;
        li->end = element;
    }
    li->len += 1;
    return li;
}

dlist_t push_front_dlist(dlist_t li, sprite_t *x)
{
    dlistnode_t *element = malloc(sizeof(dlistnode_t));

    element->particle = x;
    element->next = NULL;
    element->back = NULL;
    if (is_empty_dlist(li)) {
        li = malloc(sizeof(dlist_t));
        li->len = 0;
        li->begin = element;
        li->end = element;
    } else {
        li->begin->back = element;
        element->next = li->begin;
        li->begin = element;
    }
    li->len += 1;
    return li;
}