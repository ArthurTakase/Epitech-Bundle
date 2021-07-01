/*
** EPITECH PROJECT, 2020
** my_pustr.c
** File description:
** display character of a string
*/

#include "struct.h"

int my_putstr(char const *str)
{
    for (int count = 0; str[count] != '\0'; count++)
        my_putchar(str[count]);
    return 1;
}
