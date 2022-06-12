/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD04am-arthur.decaen
** File description:
** array_1d_to_2d
*/

#include <stdlib.h>
#include <stdio.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int step = 0;

    *res = malloc(sizeof(int *) * (height + 2));
    for (int i = 0; i < height; i++)
        (*res)[i] = malloc(sizeof(int) * (width + 2));
    for (int y = 0; y != height; y++) {
        for (int x = 0; x != width; x++) {
            (*res)[y][x] = array[step];
            step++;
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}
