/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list_p2
*/

#include <stdlib.h>
#include "proto.h"

// Ajoute un element au début de la liste | 
// Return: liste à jour
// @param li Liste à modifier
// @param value Valeur à ajouter
file_t push_front_list(file_t li, char *value)
{
    list_file_t *element = malloc(sizeof(list_file_t));

    element->trap = value;
    if (is_empty_list(li))
        element->next = NULL;
    else
        element->next = li;
    return element;
}

// Supprime un element à la fin de la liste | 
// Return: liste à jour
// @param li Liste à modifier
file_t pop_back_list(file_t li)
{
    list_file_t *temp = li;
    list_file_t *before = li;

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

// Supprime un element au début de la liste | 
// Return: liste à jour
// @param li Liste à modifier
file_t pop_front_list(file_t li)
{
    list_file_t *element = malloc(sizeof(list_file_t));

    if (is_empty_list(li))
        return li;
    element = li->next;
    free(li);
    li = NULL;
    return element;
}

// Vide completement une liste | 
// Return: liste à jour
// @param li Liste à modifier
file_t clear_list(file_t li)
{
    if (is_empty_list(li))
        return new_list();
    while (li != NULL)
        li = pop_front_list(li);
    return li;
}