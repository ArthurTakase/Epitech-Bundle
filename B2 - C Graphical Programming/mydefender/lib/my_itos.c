/*
** EPITECH PROJECT, 2020
** My_Printf
** File description:
** my_itos
*/

#include <stdlib.h>
#include "lib.h"

char *my_itos(int value, int base)
{
    int i = 0;
    int rest;
    char *buf = malloc(4096);

    while (value != 0) {
        rest = value % base;
        if (rest >= 10)
            buf[i] = rest - 10 + 'A';
        else
            buf[i] = rest + '0';
        value /= base;
        i++;
    }
    buf[i] = '\0';
    if (buf[0] == '\0')
        return "0";
    return my_revstr(buf);
}