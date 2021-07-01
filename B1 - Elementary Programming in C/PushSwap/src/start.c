/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "../include/list.h"

list_t second_part(list_t la, int min_pos)
{
    int len = list_length(la);

    while (min_pos != len) {
        la = move_rra(la);
        min_pos++;
    }
    return la;
}

list_t first_part(list_t la, int min_pos)
{
    while (min_pos > 0) {
        la = move_ra(la);
        min_pos--;
    }
    return la;
}

void start(all_list_t *list)
{
    int min_pos;

    while (!is_empty_list(list->la)) {
        min_pos = get_min(list->la);
        if (min_pos <= list_length(list->la) / 2)
            list->la = first_part(list->la, min_pos);
        else
            list->la = second_part(list->la, min_pos);
        list = move_pb(list);
    }
    print_pa(list->lb);
}

int main_criterion(int argc, char **argv)
{
    all_list_t *list;

    if (argc == 1)
        return 84;
    if (argc == 2) {
        my_putstr("\n");
        return 0;
    }
    list = init_list(argc, argv);
    if (check_order(list) == 0) {
        my_putstr("\n");
        return 0;
    }
    start(list);
    return 0;
}