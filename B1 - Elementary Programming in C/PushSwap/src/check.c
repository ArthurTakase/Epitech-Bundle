/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** check
*/

#include "../include/list.h"

int check_order(all_list_t *list)
{
    list_t temp = list->la;

    while (temp->next != NULL) {
        if (temp->value > temp->next->value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

all_list_t *init_list(int argc, char **argv)
{
    all_list_t *list = malloc(sizeof(all_list_t));

    list->la = new_list();
    list->lb = new_list();

    for (int i = 1; i != argc; i++)
        list->la = push_back_list(list->la, my_getnbr(argv[i]));
    return list;
}

void print_pa(list_t lb)
{
    for (int i = 0; i != list_length(lb); i++) {
        if (i == list_length(lb) - 1)
            my_putstr("pa\n");
        else
            my_putstr("pa ");
    }
}