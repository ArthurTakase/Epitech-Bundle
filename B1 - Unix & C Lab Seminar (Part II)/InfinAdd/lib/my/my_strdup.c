/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** duplicate string using malloc
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    int i = 0;
    char *dest = malloc(sizeof(char) * (len + 1));

    for (i; i != len; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
