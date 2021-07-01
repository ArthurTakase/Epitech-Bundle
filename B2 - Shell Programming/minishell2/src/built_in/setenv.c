/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** setenv
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <stdio.h>

char **expande_env(char *new, shell_t *shell)
{
    int len_env = len_array(shell->env);
    char **new_env = malloc(sizeof(char *) * (len_env + 2));
    int i;

    for (i = 0; i != len_env + 1; i++) {
        if (shell->env[i] != NULL)
            new_env[i] = clonestr(shell->env[i]);
        else
            new_env[i] = clonestr(new);
    }
    new_env[i] = NULL;
    clean_2darray(shell->env);
    return new_env;
}

int setenv_part(shell_t *shell, int index, int len)
{
    char *temp;
    char *temp_deux;

    if (len == 3) {
        temp = my_strcat(shell->command[1], "=");
        temp_deux = my_strcat(temp, shell->command[2]);
    } else
        temp_deux = my_strcat(shell->command[1], "=");
    shell->env[index] = clonestr(temp_deux);
    if (len == 3)
        free(temp);
    free(temp_deux);
    return 0;
}

int setenv_error(int len, shell_t *shell)
{
    if (len == 1) {
        show_env(shell);
        return 1;
    }
    if (len > 3)
        return my_error("setenv: Too many arguments.", 1);
    return 0;
}

int new_env_var(shell_t *shell, int len)
{
    char *new_var;
    char *new_var_deux;

    if (len == 3) {
        new_var = my_strcat(shell->command[1], "=");
        new_var_deux = my_strcat(new_var, shell->command[2]);
    } else
        new_var_deux = my_strcat(shell->command[1], "=");
    shell->env = expande_env(new_var_deux, shell);
    if (len == 3)
        free(new_var);
    free(new_var_deux);
    return 0;
}

int funct_setenv(shell_t *shell)
{
    int index;
    int len = len_array(shell->command);

    if (setenv_error(len, shell))
        return 1;
    index = check_loop(shell->env, shell->command[1]);
    if (index < 0)
        return new_env_var(shell, len);
    else
        return setenv_part(shell, index, len);
    return 1;
}