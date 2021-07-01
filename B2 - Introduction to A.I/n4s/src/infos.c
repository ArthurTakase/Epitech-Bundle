/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** infos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "need.h"
#include "lib.h"

char **get_infos(void)
{
    char *buff = NULL;
    size_t n = 0;
    char **infos = NULL;
    char *temp;

    my_putstr(GET_LASER "\n");
    if (getline(&buff, &n, stdin) == 0)
        exit(84);
    temp = strdup(buff);
    infos = split_str(temp, SEPARATOR);
    free(temp);
    return infos;
}

void clean_stdin(void)
{
    char *buff = NULL;
    size_t n = 0;
    getline(&buff, &n, stdin);

    free(buff);
}