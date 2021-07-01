/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** unsetenv
*/

#include "minishell.h"
#include "lib.h"

int funct_unsetenv(shell_t *shell)
{
    int index;
    int len_command = len_array(shell->command);
    int len_env = len_array(shell->env);

    if (len_command < 2)
        return my_error("unsetenv: Too few arguments.", 1);
    if (len_command == 2) {
        index = check_loop(shell->env, shell->command[1]);
        if (index == -1)
            return 1;
        for (; index != len_env; index++) {
            shell->env[index] = shell->env[index + 1];
        }
        shell->env[index] = 0;
        return 0;
    }
    return 1;
}