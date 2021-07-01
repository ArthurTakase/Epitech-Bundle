/*
** EPITECH PROJECT, 2020
** My_Printf
** File description:
** convert_print
*/

#include "struct.h"

void pr_b(va_list *args)
{
    my_putstr(my_itos(va_arg(*args, int), 2));
}

void pr_o(va_list *args)
{
    my_putstr(my_itos(va_arg(*args, int), 8));
}

void pr_x(va_list *args)
{
    my_putstr(my_strlowcase(my_itos(va_arg(*args, int), 16)));
}

void pr_majx(va_list *args)
{
    my_putstr(my_itos(va_arg(*args, int), 16));
}

void pr_u(va_list *args)
{
    put_unsigned(va_arg(*args, unsigned int));
}