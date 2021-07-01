/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** len_array
*/

#include <stdlib.h>

int len_array(char **array)
{
    int i = 0;

    if (array == NULL)
        exit(84);
    for (; *array; array++)
        i++;
    return i;
}