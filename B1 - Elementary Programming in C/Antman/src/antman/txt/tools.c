/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** tools
*/

#include "antman.h"
#include "lib.h"
#include <stdlib.h>
#include <unistd.h>

char *strfromchar(char letter)
{
    char *new = malloc(2);

    new[0] = letter;
    new[1] = '\0';
    return new;
}

int in_list(char *txt, list_t liste)
{
    list_t temp = liste;

    for (int i = 0; temp != NULL; i++) {
        if (my_strcmp(temp->elem, txt) == 0)
            return i;
        temp = temp->next;
    }
    return -1;
}

list_t init_list(char *txt)
{
    list_t temp = new_list();

    for (int i = 0; i != 256; i++) {
        temp = push_back_list(temp, strfromchar(i));
    }
    return temp;
}

void print_bin(list_t result, list_t dict)
{
    short temp;
    char un;
    char deux;

    while (result != NULL) {
        temp = result->value;
        un = temp;
        deux = temp >> 8;
        write(1, &deux, 1);
        write(1, &un, 1);
        result = result->next;
    }
    clear_list(dict, 1);
    clear_list(result, 0);
}