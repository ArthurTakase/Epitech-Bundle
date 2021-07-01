/*
** EPITECH PROJECT, 2020
** temp_printf
** File description:
** test.c
*/

#include "struct.h"

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
    void (*funct[12])(va_list *) = {pr_s, pr_d, pr_d, pr_u, pr_c, pr_cent,
                                    pr_b, pr_o, pr_o, pr_x, pr_majx, pr_majs};
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