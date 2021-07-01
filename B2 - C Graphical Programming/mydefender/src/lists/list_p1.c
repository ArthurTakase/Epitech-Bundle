/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list
*/

#include "defender.h"
#include <stdlib.h>

trap_t new_list(void)
{
    return NULL;
}

int is_empty_list(trap_t li)
{
    if (li == NULL)
        return 1;
    return 0;
}

trap_t push_back_list(trap_t li, sprite_t *value)
{
    list_trap_t *element = malloc(sizeof(*element));
    list_trap_t *temp;

    element->trap = value;
    element->next = NULL;
    if (is_empty_list(li))
        return element;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return li;
}