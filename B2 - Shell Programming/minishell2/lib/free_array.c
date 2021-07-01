/*
** EPITECH PROJECT, 2021
** B-PSU-210-BDX-2-1-minishell2-arthur.decaen
** File description:
** free_array
*/

#include <stdlib.h>
#include "lib.h"

void clean_2darray(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void clean_3darray(char ***array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        clean_2darray(array[i]);
    free(array);
}