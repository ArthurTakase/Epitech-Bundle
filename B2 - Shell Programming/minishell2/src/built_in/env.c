/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** env
*/

#include "lib.h"
#include "minishell.h"

int show_env(shell_t *shell)
{
    for (int i = 0; shell->env[i] != 0; i++) {
        my_putstr(shell->env[i]);
        my_putstr("\n");
    }
    return 0;
}