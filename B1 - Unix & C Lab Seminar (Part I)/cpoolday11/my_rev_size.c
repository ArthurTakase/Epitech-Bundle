/*
** EPITECH PROJECT, 2020
** my_rev_size.c
** File description:
** my_rev_size.c
*/

#include "include/mylist.h"
#include "include/my.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *list = NULL;
    linked_list_t *temp = *begin;
    linked_list_t *next_elem = NULL;

    while (temp != NULL) {
        next_elem = temp->next;
        temp->next = list;
        list = temp;
        temp = next_elem;
    }
    *begin = list;
}
