/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list
*/

#include <stdlib.h>
#include "../include/list.h"

list_t new_list(void)
{
    return NULL;
}

bool is_empty_list(list_t li)
{
    if (li == NULL)
        return true;
    return false;
}

int list_length(list_t li)
{
    int size = 0;

    if (!is_empty_list(li))
        while (li != NULL) {
            size++;
            li = li->next;
        }
    return size;
}

list_t push_back_list(list_t li, int value)
{
    list_element_t *element = malloc(sizeof(*element));
    list_element_t *temp;

    element->value = value;
    element->next = NULL;
    if (is_empty_list(li))
        return element;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return li;
}