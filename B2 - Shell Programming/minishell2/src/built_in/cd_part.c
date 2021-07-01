/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen
** File description:
** cd_part
*/

#include "minishell.h"
#include "lib.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int get_home(shell_t *shell)
{
    int index = check_loop(shell->env, "HOME");

    if (index < 0)
        return 1;
    if (my_strcmp(shell->home, shell->env[index] + 5)) {
        free(shell->home);
        shell->home = clonestr(shell->env[index] + 5);
        return 0;
    }
    return 1;
}

int check_dir(char *path, char *command)
{
    DIR *dir;

    if ((dir = opendir(path)) == NULL) {
        my_putstr(command);
        my_putstr(": Aucun fichier ou dossier de ce type.\n");
        return 0;
    }
    return 1;
}

int classic_cd(shell_t *shell)
{
    char *new_path = NULL;
    char *temp;
    char *temp_deux;

    new_path = getcwd(new_path, 0);
    temp = my_strcat(new_path, "/");
    temp_deux = my_strcat(temp, shell->command[1]);
    if (check_dir(temp_deux, shell->command[1])) {
        chdir(temp_deux);
        free(temp_deux);
        free(temp);
        return 0;
    }
    free(temp_deux);
    free(temp);
    return 1;
}

int home_cd(shell_t *shell)
{
    char *temp;
    char *temp_deux;

    if (shell->home == NULL)
        return errormsg(1, "No $home variable set.\n");
    temp = my_strcat(shell->home, "/");
    if (my_strlen(shell->command[1]) < 3) {
        chdir(shell->home);
        return 0;
    }
    temp_deux = my_strcat(temp, shell->command[1] + 2);
    if (check_dir(temp_deux, temp_deux)) {
        chdir(temp_deux);
        free(temp_deux);
        free(temp);
        return 0;
    }
    free(temp_deux);
    free(temp);
    return 1;
}

int cd_dot(shell_t *shell)
{
    int index_pwd;

    if ((index_pwd = check_loop(shell->env, "OLDPWD")) != -1) {
        chdir(shell->env[index_pwd] + 7);
        return 0;
    }
    return 1;
}