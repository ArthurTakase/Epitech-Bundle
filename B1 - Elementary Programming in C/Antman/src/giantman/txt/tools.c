/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen (copie)
** File description:
** tools
*/

#include <stdlib.h>
#include "lib.h"
#include "giantman.h"

list_t init_list(char *txt)
{
    list_t temp = new_list();

    for (int i = 0; i != 256; i++)
        temp = push_back_list(temp, strfromchar(i));
    return temp;
}

char *strfromchar(char letter)
{
    char *new = malloc(2);

    new[0] = letter;
    new[1] = '\0';
    return new;
}

list_t get_all_number(char *txt, char *filepath)
{
    list_t result = new_list();
    int size = size_file(filepath);
    int i = 0;
    short add;
    unsigned char un;
    unsigned char deux;

    while (i < size) {
        un = txt[i];
        deux = txt[i + 1];
        add = (((short)un) << 8) | deux;
        if (add > 255)
            result = push_back_list_int(result, add);
        else
            result = push_back_list_int(result, deux);
        i += 2;
    }
    return result;
}

int get(list_element_t **liste)
{
    int temp = (*liste)->value;
    (*liste) = (*liste)->next;
    return temp;
}

char *in_list_int(int index, list_t liste)
{
    list_t temp = liste;

    for (int i = 0; temp != NULL; i++) {
        if (i == index)
            return temp->elem;
        temp = temp->next;
    }
    return NULL;
}