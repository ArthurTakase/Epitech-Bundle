/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** path
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>
#include <string.h>

int get_nb(char *file, char elem)
{
    int nb_elem = 1;

    if (file == NULL)
        return -1;
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == elem)
            nb_elem++;
    }
    return nb_elem;
}

char **split_p(char *file, int size)
{
    char *token;
    char **result;
    int i = 0;

    if (file == NULL)
        return NULL;
    token = strtok(file, ":");
    result = malloc(sizeof(char *) * (size + 1));
    result[i] = clonestr(token);
    while ((token = strtok(NULL, ":")) != NULL) {
        i++;
        result[i] = clonestr(token);
    }
    result[i + 1] = NULL;
    return result;
}

char **get_path(char **env)
{
    int index = check_loop(env, "PATH");
    char **split_path;
    char *clone_path;
    int nb;

    if (index < 0)
        return NULL;
    clone_path = clonestr(env[index] + 5);
    if ((nb = get_nb(clone_path, ':')) == -1)
        return NULL;
    if ((split_path = split_p(clone_path, nb)) == NULL)
        return NULL;
    return split_path;
}