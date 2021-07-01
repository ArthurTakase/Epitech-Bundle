/*
** EPITECH PROJECT, 2020
** My_Printf
** File description:
** convert_print
*/

#include <stdarg.h>

int my_putstr(char const *str);

char *my_strlowcase(char *str);

char *my_itos(int value, int base);

int put_unsigned(unsigned int nb);

void print_b(va_list *args)
{
    my_putstr(my_itos(va_arg(*args, int), 2));
}

void print_o(va_list *args)
{
    my_putstr(my_itos(va_arg(*args, int), 8));
}

void print_x(va_list *args)
{
    my_putstr(my_strlowcase(my_itos(va_arg(*args, int), 16)));
}

void print_x2(va_list *args)
{
    my_putstr(my_itos(va_arg(*args, int), 16));
}

void print_u(va_list *args)
{
    put_unsigned(va_arg(*args, unsigned int));
}