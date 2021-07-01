/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** cd
*/

#include "minishell.h"
#include "lib.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int funct_cd(shell_t *shell)
{
    if (len_array(shell->command) > 2)
        return errormsg(1, "cd: Too many arguments.\n");
    if (len_array(shell->command) == 1 || my_strncmp(shell->command[1], "~") ||
        my_strncmp(shell->command[1], "~-") ||
        !my_strcmp(shell->command[1], "--")) {
        get_home(shell);
        return home_cd(shell);
    }
    if (my_strncmp(shell->command[1], "/")) {
        if (check_dir(shell->command[1], shell->command[1])) {
            chdir(shell->command[1]);
            return 0;
        }
        return 1;
    }
    if (!my_strcmp(shell->command[1], "-"))
        return cd_dot(shell);
    return classic_cd(shell);
}