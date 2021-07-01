/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-42sh-arthur.decaen
** File description:
** my_strspc
*/

#include "minishell.h"

int my_strspn(char *str, char **limit, int *limit_selected)
{
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; limit[j] != NULL; j++) {
            if (check_start(str + i, limit[j])) {
                *limit_selected = j;
                return i;
            }
        }
    }
    return -1;
}