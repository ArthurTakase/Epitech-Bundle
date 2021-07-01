/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list
*/

#include <stdlib.h>
#include "antman.h"

list_t new_list(void)
{
    return NULL;
}

list_t push_back_list(list_t li, char *value)
{
    list_element_t *element = malloc(sizeof(list_element_t));
    list_element_t *temp;

    element->elem = value;
    element->next = NULL;
    if (li == NULL)
        return element;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return li;
}

list_t push_back_list_int(list_t li, int value)
{
    list_element_t *element = malloc(sizeof(list_element_t));
    list_element_t *temp;

    element->value = value;
    element->next = NULL;
    if (li == NULL)
        return element;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return li;
}

list_t pop_front_list(list_t li, int flag)
{
    list_element_t *element;

    if (li == NULL)
        return li;
    element = li->next;
    if (flag == 1)
        free(li->elem);
    free(li);
    li = NULL;
    return element;
}

list_t clear_list(list_t li, int flag)
{
    if (li == NULL)
        return new_list();
    while (li != NULL)
        li = pop_front_list(li, flag);
    return li;
}