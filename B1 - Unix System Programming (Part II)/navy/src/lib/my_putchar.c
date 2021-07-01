/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** write char
*/

#include "struct.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
