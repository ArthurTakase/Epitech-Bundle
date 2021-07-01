/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** get_env
*/

#include "lib.h"
#include "minishell.h"
#include <stdlib.h>

char **my_clone(char **src)
{
    int len = len_array(src);
    char **new = malloc(sizeof(char *) * (len + 1));
    int i;

    for (i = 0; i != len; i++)
        new[i] = clonestr(src[i]);
    new[i] = NULL;
    return new;
}

int check_start(char *env, char *search)
{
    if (my_strlen(env) < my_strlen(search))
        return 0;
    for (int i = 0; search[i] != '\0'; i++)
        if (search[i] != env[i])
            return 0;
    return 1;
}

int check_loop(char **env, char *search)
{
    char *temp = my_strcat(search, "=");

    if (len_array(env) != 0)
        for (int i = 0; env[i]; i++) {
            if (check_start(env[i], temp)) {
                free(temp);
                return i;
            }
        }
    free(temp);
    return -1;
}