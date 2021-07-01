/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list
*/

#include "struct.h"

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

int list_length(trap_t li)
{
    int size = 0;

    if (!is_empty_list(li))
        while (li != NULL) {
            size++;
            li = li->next;
        }
    return size;
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