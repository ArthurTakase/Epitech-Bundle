/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** stack_move
*/

#include "stack.h"

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}

bool stack_pop(stack_t *stack_ptr)
{
    return list_del_elem_at_front(stack_ptr);
}

void stack_clear(stack_t *stack_ptr)
{
    list_clear(stack_ptr);
}
