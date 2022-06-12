/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
** File description:
** concat
*/

#include "concat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat_strings(const char *str1, const char *str2, char **res)
{
    char *result = malloc(strlen(str1) + strlen(str2) + 1);
    int i = 0;
    int j = 0;

    for (; str1[j] != '\0'; j++)
        result[j] = str1[j];
    for (; str2[i] != '\0'; i++)
        result[j + i] = str2[i];
    result[j + i] = '\0';
    *res = result;
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}
