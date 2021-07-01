/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** my_strcmp
*/

#include <string.h>

int my_strcmp(char const *s1, char const *s2)
{
    if (strlen(s1) != strlen(s2))
        return -1;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2)
{
    for (int i = 0; s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}