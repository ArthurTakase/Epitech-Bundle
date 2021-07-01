/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** move
*/


#include <stdlib.h>
#include "../include/list.h"

all_list_t *move_pb(all_list_t *list)
{
    my_putstr("pb ");
    list->lb = push_front_list(list->lb, list->la->value);
    list->la = pop_front_list(list->la);
    return list;
}

list_t move_rra(list_t la)
{
    list_element_t *temp = la;

    my_putstr("rra ");
    while (temp->next != NULL) {
        temp = temp->next;
    }
    la = push_front_list(la, temp->value);
    la = pop_back_list(la);
    return la;
}

list_t move_ra(list_t la)
{
    my_putstr("ra ");
    la = push_back_list(la, la->value);
    la = pop_front_list(la);
    return la;
}