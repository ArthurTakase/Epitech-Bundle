/*
** EPITECH PROJECT, 2021
** backup
** File description:
** exe_built
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>

int in_list(char *commande)
{
    char *create[5] = {"cd", "setenv", "unsetenv", "env", "echo"};

    for (int i = 0; i != 5; i++) {
        if (!my_strcmp(commande, create[i]))
            return i;
    }
    return -1;
}

void update_path(shell_t *shell)
{
    int len;

    if (shell->path != NULL) {
        len = len_array(shell->path);
        for (int i = 0; i != len; i++)
            free(shell->path[i]);
        free(shell->path);
    }
    shell->path = get_path(shell->env);
}

int execute_built(shell_t *shell, dlistnode_t *temp)
{
    static int index;
    static int(*funct[5])(shell_t *) = {funct_cd, funct_setenv,
                                        funct_unsetenv, show_env, funct_echo};

    if ((index = in_list(shell->command[0])) != -1) {
        shell->temp = temp;
        (*funct[index])(shell);
        edit_oldpwd(shell);
        edit_pwd(shell);
        if (len_array(shell->command) > 1 &&
            !my_strcmp(shell->command[1], "PATH"))
            update_path(shell);
        return 1;
    }
    return 0;
}