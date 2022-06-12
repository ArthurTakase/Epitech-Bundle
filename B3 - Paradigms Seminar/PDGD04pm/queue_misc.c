/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** queue_misc
*/

#include "queue.h"

void *queue_front(queue_t queue)
{
    return list_get_elem_at_front(queue);
}

unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}
