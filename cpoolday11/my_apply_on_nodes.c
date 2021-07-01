/*
** EPITECH PROJECT, 2020
** my apply on nodes
** File description:
** my apply on nodes
*/

#include "include/mylist.h"
#include <stddef.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    while (begin != NULL) {
        (*f)(begin->data);
        begin = begin->next;
    }
    return 0;
}
