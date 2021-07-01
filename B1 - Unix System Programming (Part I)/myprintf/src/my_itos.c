/*
** EPITECH PROJECT, 2020
** My_Printf
** File description:
** my_itos
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *my_itos(int value, int base)
{
    int i = 0;
    int rest;
    char *buf = malloc(4096);

    for (i; value != 0; i++) {
        rest = value % base;
        if (rest >= 10)
            buf[i] = rest - 10 + 'A';
        else
            buf[i] = rest + '0';
        value /= base;
    }
    buf[i] = '\0';
    return my_revstr(buf);
}