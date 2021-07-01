/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>
#include "lib.h"

char *my_strcat(char *dest, char const *src)
{
    int max = my_strlen(dest) + my_strlen(src);
    char *result = malloc(max + 1);
    int i = 0;
    int j = 0;

    for (; dest[j] != '\0'; j++)
        result[j] = dest[j];
    for (; src[i] != '\0'; i++)
        result[j + i] = src[i];
    result[j + i] = '\0';
    return result;
}