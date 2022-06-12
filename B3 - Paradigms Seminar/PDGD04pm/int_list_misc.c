/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04pm-arthur.decaen
** File description:
** del_list
*/

#include "int_list.h"
#include <stdlib.h>
#include <stdio.h>

bool int_list_is_empty(int_list_t list) {
    if (list == NULL)
        return true;
    return false;
}

unsigned int int_list_get_size(int_list_t list) {
    unsigned int size = 0;

    if (!int_list_is_empty(list))
        while (list != NULL) {
            size++;
            list = list->next;
        }
    return size;
}

void int_list_dump(int_list_t list) {
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}
