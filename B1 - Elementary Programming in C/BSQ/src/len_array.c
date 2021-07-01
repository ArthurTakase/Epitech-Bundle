/*
** EPITECH PROJECT, 2020
** Bootstrap BSQ
** File description:
** tools
*/


#include "../include/my.h"

// Returns the height of the field
int height(char *file)
{
    int height = 0;

    for (int i = 0; file[i] != '\0'; i++)
        if (file[i] == '\n')
            height += 1;
    return height;
}

//Returns the width of the field
int width(char *file, int height)
{
    int width = 0;

    for (int j = len_nbr(height) + 1; file[j] != '\n'; j++)
        width += 1;
    return width;
}