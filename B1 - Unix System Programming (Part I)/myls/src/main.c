/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** main
*/

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_printf.h"
#include "../include/my.h"

void l_option(char const *filepath, char const *name);

char *parse_command(int argc, char **argv);

char **parse_dir(int argc, char **argv);

void ls_options(char *temp, char *command, struct dirent *d) {
    if (d->d_name[0] == '.' && !my_in('a', command))
        return;
    else if (my_in('l', command))
        l_option(my_strcat(temp, d->d_name), d->d_name);
    else
        my_printf("%s\t", d->d_name);
}

int ls(char *filepath, char *command)
{
    struct dirent *d = malloc(sizeof(struct dirent));
    DIR *dir = opendir(filepath);
    char *temp = malloc(sizeof(filepath) + 2);

    if (dir == NULL)
        return 84;
    while ((d = readdir(dir))) {
        temp[0] = 0;
        if (my_strcmp(filepath, "./") != 0)
            temp = my_strcat(my_strcpy(temp, filepath), "/");
        ls_options(temp, command, d);
    }
    closedir(dir);
    return 0;
}

int main(int argc, char **argv)
{
    char **dir_list = parse_dir(argc, argv);
    char *command = parse_command(argc, argv);
    int temp_return;

    if (dir_list[0] == NULL)
        temp_return = ls("./", command);
    else
        temp_return = ls(dir_list[0], command);
    free(command);
    free(dir_list);
    return temp_return;
}