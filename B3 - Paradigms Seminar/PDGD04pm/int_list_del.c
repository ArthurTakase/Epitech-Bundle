/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** del_list
*/

#include "int_list.h"
#include <stdlib.h>

bool int_list_del_elem_at_position(int_list_t *front_ptr,
                                    unsigned int position)
{
    int_node_t *to_remove;
    int_node_t *temp;
    int size = int_list_get_size(*front_ptr);

    if (int_list_is_empty(*front_ptr) || position > (unsigned int)size)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    if (position == (unsigned int)size)
        return int_list_del_elem_at_back(front_ptr);
    temp = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++)
        temp = temp->next;
    to_remove = temp->next;
    temp->next = temp->next->next;
    free(to_remove);
    return true;
}

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_node_t *temp = *front_ptr;

    if (int_list_is_empty(*front_ptr))
        return false;
    (*front_ptr) = (*front_ptr)->next;
    free(temp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_node_t *temp = *front_ptr;
    int_node_t *before = *front_ptr;

    if (int_list_is_empty(*front_ptr))
        return false;
    while (temp->next != NULL) {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    return true;
}

void int_list_clear(int_list_t *front_ptr)
{
    while ((*front_ptr)->next != NULL)
        int_list_del_elem_at_back(front_ptr);
    int_list_del_elem_at_front(front_ptr);
}