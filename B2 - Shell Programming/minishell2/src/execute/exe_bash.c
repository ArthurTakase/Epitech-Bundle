/*
** EPITECH PROJECT, 2021
** backup
** File description:
** exe_bash
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int exe_bash(shell_t *shell)
{
    int index;
    char *pwd;
    char *pwd_deux;

    if ((index = check_loop(shell->env, "PWD")) == -1)
        return 0;
    pwd = shell->env[index] + 4;
    pwd = my_strcat(pwd, "/");
    pwd_deux = my_strcat(pwd, shell->command[0]);
    execve(pwd_deux, shell->command, shell->env);
    free(pwd);
    free(pwd_deux);
    return 1;
}