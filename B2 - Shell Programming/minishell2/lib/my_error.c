/*
** EPITECH PROJECT, 2021
** minishell2 (67.5%, crash)
** File description:
** my_error
*/

#include "minishell.h"

int my_error(char const *msg, int const x)
{
    my_putstr(msg);
    my_putstr("\n");
    return x;
}