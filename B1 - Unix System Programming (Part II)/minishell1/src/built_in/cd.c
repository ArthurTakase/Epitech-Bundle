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
    char *temp = my_strcat(shell->home, "/");
    char *temp_deux;

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

int funct_cd(shell_t *shell)
{
    if (my_strncmp(shell->command[1], "~")) {
        get_home(shell);
        return home_cd(shell);
    }
    else if (my_strncmp(shell->command[1], "/")) {
        if (check_dir(shell->command[1], shell->command[1])) {
            chdir(shell->command[1]);
            return 0;
        }
        return 1;
    } else
        return classic_cd(shell);
    return 1;
}