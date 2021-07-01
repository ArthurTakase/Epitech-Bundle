/*
** EPITECH PROJECT, 2020
** my_delete_nodes.c
** File description:
** my_delete_nodes.c
*/

#include "include/mylist.h"
#include <stddef.h>
#include <stdlib.h>

int my_delete_nodes(linked_list_t **begin, void const *data_ref, int (*cmp)())
{
    linked_list_t *tmp = NULL;
    linked_list_t *current = *begin;

    while (current->next != NULL) {
        if (tmp == NULL && (*cmp)(current->data, data_ref) == 0) {
            *begin = current->next;
            current = current->next;
            continue;
        }
        tmp = current->next;
        if ((*cmp)(tmp->data, data_ref) == 0) {
            current->next = tmp->next;
        } else {
            current = current->next;
        }
    }
}
