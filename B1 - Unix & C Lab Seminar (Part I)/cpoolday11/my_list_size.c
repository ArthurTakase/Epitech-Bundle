/*
** EPITECH PROJECT, 2020
** my_list_size.c
** File description:
** my_list_size.c
*/

#include "include/mylist.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    int count = 0;
    linked_list_t const *temp;

    temp = begin;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
