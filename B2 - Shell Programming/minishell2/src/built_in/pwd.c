/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen
** File description:
** pwd
*/

#include "minishell.h"
#include "lib.h"
#include <stdlib.h>
#include <unistd.h>

void edit_oldpwd(shell_t *shell)
{
    int index_pwd = check_loop(shell->env, "PWD");
    int index_oldpwd = check_loop(shell->env, "OLDPWD");
    char *var_env;

    if (index_oldpwd == -1 || index_pwd == -1)
        return;
    else {
        var_env = my_strcat("OLDPWD=", shell->env[index_pwd] + 4);
        shell->env[index_oldpwd] = clonestr(var_env);
        free(var_env);
    }
}

void edit_pwd(shell_t *shell)
{
    int index_pwd = check_loop(shell->env, "PWD");
    char *var_env;
    size_t n = 0;
    char *pwd = NULL;

    if (index_pwd == -1)
        return;
    else {
        var_env = my_strcat("PWD=", getcwd(pwd, n));
        shell->env[index_pwd] = clonestr(var_env);
        free(pwd);
        free(var_env);
    }
}