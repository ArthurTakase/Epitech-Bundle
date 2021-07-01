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

void clean_path(char **path)
{
    if (path == NULL)
        return;
    for (int i = 0; path[i] != NULL; i++)
        free(path[i]);
    free(path);
}

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
    int nb;

    if (index < 0)
        return NULL;
    if ((nb = get_nb(env[index] + 5, ':')) == -1)
        return NULL;
    if ((split_path = split_p(env[index] + 5, nb)) == NULL)
        return NULL;
    return split_path;
}