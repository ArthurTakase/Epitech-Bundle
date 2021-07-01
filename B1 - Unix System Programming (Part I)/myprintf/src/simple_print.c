/*
** EPITECH PROJECT, 2020
** My_Printf
** File description:
** all_print
*/

#include <stdarg.h>

int my_putstr(char const *str);

int my_put_nbr(int nb);

int my_putchar(char c);

char *my_itos(int value, int base);

void print_s(va_list *args)
{
    my_putstr(va_arg(*args, char *));
}

void print_d(va_list *args)
{
    my_put_nbr(va_arg(*args, int));
}

void print_c(va_list *args)
{
    my_putchar(va_arg(*args, int));
}

void print_cent(va_list *args)
{
    my_putchar('%');
}

void print_s2(va_list *args)
{
    char *str = va_arg(*args, char *);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_putstr(my_itos(str[i], 8));
        } else
            my_putchar(str[i]);
    }
}