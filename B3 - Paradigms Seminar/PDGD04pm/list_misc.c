/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** del_list
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

unsigned int list_get_size(list_t list)
{
    unsigned int size = 0;

    if (!list_is_empty(list))
        while (list != NULL) {
            size++;
            list = list->next;
        }
    return size;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list != NULL) {
        (val_disp)(list->value);
        list = list->next;
    }
}
