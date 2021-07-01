/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** how_many_in
*/

#include <stdlib.h>

int how_many_in(char *src, char what)
{
    int temp = 0;

    if (src == NULL)
        return temp;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == what)
            temp++;
    }
    return temp;
}