/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-42sh-arthur.decaen
** File description:
** echo
*/

#include "minishell.h"

char *value_from_env(char *env_var, shell_t *shell)
{
    int index = check_loop(shell->env, env_var);

    if (index == -1)
        return NULL;
    return shell->env[index] + my_strlen(env_var) + 1;
}

int replace_value_echo(shell_t *shell)
{
    char *temp;

    for (int i = 1; shell->command[i] != NULL; i++) {
        if (shell->command[i][0] == '$') {
            temp = clonestr(shell->command[i]);
            shell->command[i] = value_from_env(shell->command[i] + 1, shell);
            if (shell->command[i] == NULL) {
                errormsg(0, temp + 1);
                free(temp);
                return errormsg(0, ": Undefined variable.\n");
            }
        }
    }
    return 1;
}

int funct_echo(shell_t *shell)
{
    int len;

    if (how_many_in(shell->temp->infos->original_cmd, "\"") % 2 != 0)
        return errormsg(1, "Unmatched '\"'.\n");
    if (!replace_value_echo(shell))
        return 1;
    len = len_array(shell->command);
    for (int i = 1; shell->command[i] != NULL; i++) {
        my_putstr(shell->command[i]);
        if (i != len - 1)
            my_putstr(" ");
    }
    my_putstr("\n");
    return 0;
}