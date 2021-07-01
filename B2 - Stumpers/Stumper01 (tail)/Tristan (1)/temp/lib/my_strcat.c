/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    char *result = malloc(len_dest + my_strlen(src));
    int i = 0;

    for (i; i < len_dest + my_strlen(src); i++) {
        if (i < len_dest)
            result[i] = dest[i];
        else
            result[i] = src[i - len_dest - 1];
    }
    return result;
}
