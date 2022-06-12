/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** stack_misc
*/

#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}

void *stack_top(stack_t stack)
{
    return list_get_elem_at_front(stack);
}