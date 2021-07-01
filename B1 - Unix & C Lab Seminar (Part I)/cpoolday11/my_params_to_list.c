/*
** EPITECH PROJECT, 2020
** my_params_to_list.c
** File description:
** my_params_to_list.c
*/

#include <stdlib.h>
#include "include/mylist.h"
#include <stddef.h>

int my_put_in_list(linked_list_t **list, char *av)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = av;
    element->next = *list;
    *list = element;
    return 0;
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;

    list = NULL;
    for (int i = 0; i < ac; i++)
        my_put_in_list(&list, av[i]);
    return list;
}
