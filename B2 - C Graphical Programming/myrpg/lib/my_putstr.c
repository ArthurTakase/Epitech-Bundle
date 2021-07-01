/*
** EPITECH PROJECT, 2020
** my_pustr.c
** File description:
** displat chacter of a string
*/

#include <unistd.h>
#include "lib.h"

void my_putstr(char const *str)
{
    int size = my_strlen(str);

    write(1, str, size);
}
