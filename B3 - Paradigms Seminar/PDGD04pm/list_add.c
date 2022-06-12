/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** del_list
*/

#include "list.h"
#include <stdlib.h>

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
                                    unsigned int position)
{
    node_t *element = malloc(sizeof(node_t));
    node_t *temp;
    int size = list_get_size(*front_ptr);

    if (element == NULL || position > (unsigned int)size)
        return false;
    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    element->value = elem;
    if (list_is_empty(*front_ptr))
        *front_ptr = element;
    temp = *front_ptr;
    for (unsigned int i = 0; i < position - 1; i++)
        temp = temp->next;
    element->next = temp->next;
    temp->next = element;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *element = malloc(sizeof(node_t));
    node_t *temp;

    if (element == NULL)
        return false;
    element->value = elem;
    element->next = NULL;
    if (list_is_empty(*front_ptr)) {
        *front_ptr = element;

    } else {
        temp = *front_ptr;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = element;
    }
    return true;
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *element = malloc(sizeof(node_t));

    if (element == NULL)
        return false;
    element->value = elem;
    if (list_is_empty(*front_ptr))
        element->next = NULL;
    else
        element->next = *front_ptr;
    *front_ptr = element;
    return true;
}
