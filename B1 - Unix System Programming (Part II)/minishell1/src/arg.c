/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** arg
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell.h"
#include "lib.h"

int get_word(char *txt)
{
    char *temp = clonestr(txt);
    char *token = strtok(temp, " ");
    int i = 1;

    while ((token = strtok(NULL, " ")) != NULL)
        i++;
    free(temp);
    return i;
}

char **split(char *txt)
{
    int nb_word = get_word(txt);
    char *token = strtok(txt, " ");
    char **result = malloc(sizeof(char *) * (nb_word + 1));
    int i = 0;

    result[i] = clonestr(token);
    while ((token = strtok(NULL, " ")) != NULL) {
        i++;
        result[i] = clonestr(token);
    }
    result[i + 1] = NULL;
    return result;
}

char **get_command(void)
{
    size_t n = 0;
    char *buffer = NULL;
    char **user;
    int len;

    if (getline(&buffer, &n, stdin) == -1)
        exit(0);
    len = my_strlen(buffer);
    if (buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
    user = split(buffer);
    free(buffer);
    return user;
}