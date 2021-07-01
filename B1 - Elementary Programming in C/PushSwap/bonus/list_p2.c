/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list_p2
*/

#include <stdlib.h>
#include "../include/list.h"

list_t push_front_list(list_t li, int value)
{
    list_element_t *element = malloc(sizeof(*element));
    list_element_t *temp;

    element->value = value;
    if (is_empty_list(li))
        element->next = NULL;
    else
        element->next = li;
    return element;
}

list_t pop_back_list(list_t li)
{
    list_element_t *temp = li;
    list_element_t *before = li;

    if (is_empty_list(li))
        return new_list();
    if (li->next == NULL) {
        free(li);
        return new_list();
    }
    while (temp->next != NULL) {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    return li;
}

list_t pop_front_list(list_t li)
{
    list_element_t *element = malloc(sizeof(*element));

    if (is_empty_list(li))
        return li;
    element = li->next;
    free(li);
    li = NULL;
    return element;
}

list_t clear_list(list_t li)
{
    if (is_empty_list(li))
        return new_list();
    while (li != NULL)
        li = pop_front_list(li);
    return li;
}

int get_min(list_t li)
{
    list_t temp = li;
    int min_value = temp->value;
    int pos_value = 0;
    int pos = 0;

    while (temp != NULL) {
        if (temp->value <= min_value) {
            min_value = temp->value;
            pos_value = pos;
        }
        pos++;
        temp = temp->next;
    }
    return pos_value;
}