/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-42sh-arthur.decaen
** File description:
** my_strtok_r
*/

#include "minishell.h"

char *my_strtok_r(char *str, char **limit, char **saveptr)
{
    int limit_select = -1;
    char *str_temp;
    int i = my_strspn(str, limit, &limit_select);

    if (i == -1 || limit_select == -1) {
        *saveptr = NULL;
        return str;
    }
    *saveptr = str + i + my_strlen(limit[limit_select]);
    if (my_strlen(*saveptr) == 0)
        *saveptr = NULL;
    str_temp = dup_len(str, i);
    str = clean_str(str_temp);
    free(str_temp);
    return str;
}