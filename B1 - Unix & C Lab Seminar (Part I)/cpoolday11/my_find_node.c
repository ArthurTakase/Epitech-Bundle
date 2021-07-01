/*
** EPITECH PROJECT, 2020
** my_find_node.c
** File description:
** my_find_node.c
*/

#include "include/mylist.h"
#include <stddef.h>

linked_list_t *my_find_node(linked_list_t const *begin,
                            void const *data_ref, int (*cmp)())
{
    linked_list_t *current = begin;

    while (current != NULL) {
        if ((*cmp)(current->data, data_ref) == 0)
            return current;
        current = current->next;
    }
    return current;
}
