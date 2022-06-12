/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** del_list
*/

#include "int_list.h"
#include <stdlib.h>

int int_list_get_elem_at_front(int_list_t list)
{
    if (int_list_is_empty(list))
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    int_list_t temp;

    if (int_list_is_empty(list))
        return 0;
    temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    return temp->value;
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    int_node_t *temp = list;

    if (int_list_is_empty(list) || int_list_get_size(list) < position)
        return 0;
    for (unsigned int i = 0; i < position; i++)
        temp = temp->next;
    return temp->value;
}
