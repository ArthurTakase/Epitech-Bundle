/*
** EPITECH PROJECT, 2020
** temp_printf
** File description:
** test.c
*/

#include <stdarg.h>
#include <stdio.h>

void print_s2(va_list *my_list);

void print_cent(va_list *my_list);

void print_c(va_list *my_list);

void print_d(va_list *my_list);

void print_s(va_list *my_list);

void print_b(va_list *my_list);

void print_o(va_list *my_list);

void print_x(va_list *my_list);

void print_x2(va_list *my_list);

void print_u(va_list *args);

int my_putchar(char c);

int index_function(char *choice, char letter)
{
    for (int i = 0; choice[i] != 0; i++)
        if (choice[i] == letter)
            return i;
    return -1;
}

void my_printf(char const *str, ...)
{
    va_list args;
    int temp_index;
    void (*funct[12])(va_list *) = {print_s, print_d, print_d, print_u,
                                    print_c, print_cent, print_b, print_o,
                                    print_o, print_x, print_x2, print_s2};
    char idx[13] = {'s', 'd', 'i', 'u', 'c', '%',
                    'b', 'o', 'O', 'x', 'X', 'S', 0};

    va_start(args, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && index_function(idx, str[i + 1]) != -1) {
            temp_index = index_function(idx, str[i + 1]);
            if (temp_index != -1)
                (*funct[temp_index])(&args);
            i++;
        } else
            my_putchar(str[i]);
    }
    va_end(args);
}