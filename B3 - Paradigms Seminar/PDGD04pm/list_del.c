/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** del_list
*/

#include "list.h"
#include <stdlib.h>

bool list_del_elem_at_position(list_t *front_ptr,
                                    unsigned int position)
{
    node_t *to_remove;
    node_t *temp;
    int size = list_get_size(*front_ptr);

    if (list_is_empty(*front_ptr) || position > (unsigned int)size)
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    if (position == (unsigned int)size)
        return list_del_elem_at_back(front_ptr);
    temp = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++)
        temp = temp->next;
    to_remove = temp->next;
    temp->next = temp->next->next;
    free(to_remove);
    return true;
}

bool list_del_elem_at_front(list_t *front_ptr)
{
    node_t *temp = *front_ptr;

    if (list_is_empty(*front_ptr))
        return false;
    (*front_ptr) = (*front_ptr)->next;
    free(temp);
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *temp = *front_ptr;
    node_t *before = *front_ptr;

    if (list_is_empty(*front_ptr))
        return false;
    while (temp->next != NULL) {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    return true;
}

void list_clear(list_t *front_ptr)
{
    while ((*front_ptr)->next != NULL)
        list_del_elem_at_back(front_ptr);
    list_del_elem_at_front(front_ptr);
}