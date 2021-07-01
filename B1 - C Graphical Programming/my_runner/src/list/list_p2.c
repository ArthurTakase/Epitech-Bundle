/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list_p2
*/

#include "struct.h"

trap_t push_front_list(trap_t li, sprite_t *value)
{
    list_trap_t *element = malloc(sizeof(*element));

    element->trap = value;
    if (is_empty_list(li))
        element->next = NULL;
    else
        element->next = li;
    return element;
}

trap_t pop_back_list(trap_t li)
{
    list_trap_t *temp = li;
    list_trap_t *before = li;

    if (is_empty_list(li))
        return new_list();
    if (li->next == NULL) {
        free(li);
        return new_list();
    }
    while (temp->next != NULL) {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    return li;
}

trap_t pop_front_list(trap_t li)
{
    list_trap_t *element = malloc(sizeof(*element));

    if (is_empty_list(li))
        return li;
    element = li->next;
    free(li);
    li = NULL;
    return element;
}

trap_t clear_list(trap_t li)
{
    if (is_empty_list(li))
        return new_list();
    while (li != NULL)
        li = pop_front_list(li);
    return li;
}