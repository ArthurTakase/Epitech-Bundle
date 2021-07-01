/*
** EPITECH PROJECT, 2020
** my_pustr.c
** File description:
** displat chacter of a string
*/

#include <unistd.h>

int my_strlen(char const *str);

void my_putstr(char const *str)
{
    int size = my_strlen(str);

    write(1, str, size);
}
