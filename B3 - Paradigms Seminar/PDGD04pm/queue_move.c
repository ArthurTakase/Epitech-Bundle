/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** queue_move
*/

#include "queue.h"

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return list_add_elem_at_back(queue_ptr, elem);
}

bool queue_pop(queue_t *queue_ptr)
{
    return list_del_elem_at_front(queue_ptr);
}

void queue_clear(queue_t *queue_ptr)
{
    list_clear(queue_ptr);
}
