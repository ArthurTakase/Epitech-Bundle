/*
** EPITECH PROJECT, 2021
** backup
** File description:
** exe_built
*/

#include "lib.h"
#include "minishell.h"

int in_list(char *commande)
{
    char *create[4] = {"cd", "setenv", "unsetenv", "env"};

    for (int i = 0; i != 4; i++) {
        if (!my_strcmp(commande, create[i]))
            return i;
    }
    return -1;
}

int execute_built(shell_t *shell)
{
    static int index;
    static int(*funct[4])(shell_t *) = {funct_cd, funct_setenv,
                                        funct_unsetenv, show_env};

    if ((index = in_list(shell->command[0])) != -1) {
        (*funct[index])(shell);
        return 1;
    }
    return 0;
}