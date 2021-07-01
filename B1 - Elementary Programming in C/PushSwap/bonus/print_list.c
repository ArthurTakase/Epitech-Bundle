/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** print_list
*/

#include "../include/list.h"

void print_list(list_t li)
{
    if (is_empty_list(li)) {
        my_putstr("liste Vide\n");
        return;
    }
    while (li != NULL) {
        my_putstr("[");
        my_put_nbr(li->value);
        my_putstr("] ");
        li = li->next;
    }
    my_putstr("\n");
}