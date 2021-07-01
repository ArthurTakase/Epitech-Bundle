/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** list
*/

#include <stdlib.h>
#include "proto.h"

// Initialisation d'une nouvelle liste | 
// Return: NULL
file_t new_list(void)
{
    return NULL;
}

// Return: 1 si liste vide, 0 sinon
// @param li Liste à examiner
int is_empty_list(file_t li)
{
    if (li == NULL)
        return 1;
    return 0;
}

// Return: Longueur de la liste
// @param li Liste à examiner
int list_length(file_t li)
{
    int size = 0;

    if (!is_empty_list(li))
        while (li != NULL) {
            size++;
            li = li->next;
        }
    return size;
}

// Ajoute un element à la fin de la liste | 
// Return: liste à jour
// @param li Liste à modifier
// @param value Valeur à ajouter
file_t push_back_list(file_t li, char *value)
{
    list_file_t *element = malloc(sizeof(list_file_t));
    list_file_t *temp;

    element->trap = value;
    element->next = NULL;
    if (is_empty_list(li))
        return element;
    temp = li;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = element;
    return li;
}