/*
** EPITECH PROJECT, 2020
** my_concat_list
** File description:
** my_concat_list
*/

#include "include/mylist.h"
#include <stddef.h>

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *temp = *begin1;

    if (temp == NULL) {
        *begin1 = begin2;
    } else {
        my_concat_list(&(temp->next), begin2);
    }
}
