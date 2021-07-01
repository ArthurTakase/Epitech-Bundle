/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-42sh-arthur.decaen
** File description:
** dup_len
*/

#include "minishell.h"

char *dup_len(char *txt, int len)
{
    char *result = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (; txt[i] != '\0' && i != len; i++)
        result[i] = txt[i];
    result[i] = '\0';
    return result;
}