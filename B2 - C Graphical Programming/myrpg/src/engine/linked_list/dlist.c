/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** linked_list
*/

#include "rpg.h"
#include <stdlib.h>

dlist_t new_dlist(void)
{
    return NULL;
}

int is_empty_dlist(dlist_t li)
{
    if (li == NULL)
        return 1;
    return 0;
}

int dlist_len(dlist_t li)
{
    if (is_empty_dlist(li))
        return 0;
    return li->len;
}