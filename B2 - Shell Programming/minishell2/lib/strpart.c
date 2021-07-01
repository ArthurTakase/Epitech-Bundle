/*
** EPITECH PROJECT, 2021
** minishell2 (77.5%, functionnal)
** File description:
** strpart
*/

#include "lib.h"
#include <stdlib.h>

char *copy_strpart(char *txt, int start, int *len, char *sep)
{
    char *temp = malloc(sizeof(char) * my_strlen(txt));
    int index = 0;
    char *result;
    int i = start;

    if (txt[i] == ' ')
        i++;
    for (; !my_in(txt[i], sep) && txt[i] != '\0'; i++) {
        temp[index] = txt[i];
        index++;
    }
    temp[index] = '\0';
    *len = my_strlen(temp);
    result = clean_str(temp);
    free(temp);
    return result;
}

char *rm_strpart(char *txt, int start, int len)
{
    char *result = malloc(sizeof(char) * (my_strlen(txt) + 1));
    int i = 0;
    int index = 0;

    for (; txt[i] != '\0'; i++) {
        if (i >= start && i <= start + len)
            continue;
        result[index] = txt[i];
        index++;
    }
    result[index] = '\0';
    return result;
}