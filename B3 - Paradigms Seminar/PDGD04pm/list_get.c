/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** del_list
*/

#include "list.h"
#include <stdlib.h>

void *list_get_elem_at_front(list_t list)
{
    if (list_is_empty(list))
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    list_t temp;

    if (list_is_empty(list))
        return 0;
    temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    return temp->value;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    node_t *temp = list;

    if (list_is_empty(list) || list_get_size(list) < position)
        return 0;
    for (unsigned int i = 0; i < position; i++)
        temp = temp->next;
    return temp->value;
}
