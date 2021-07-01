/*
** EPITECH PROJECT, 2020
** Bootstrap BSQ
** File description:
** step1.c
*/

#include <stdlib.h>

// Transforms a char * into a 2d array
char **load_2d_arr_from_file(char const *readfile, int nb_rows, int nb_cols)
{
    char **file2d = malloc(sizeof(char *) * nb_rows + 2);
    int y = 0;
    int x = 0;

    for (int i = 0; i < nb_rows; i++)
        file2d[i] = malloc(sizeof(char) * nb_cols + 2);
    for (int z = 0; readfile[z] != '\0'; ++z) {
        if (readfile[z] == '\n') {
            y++;
            x = 0;
        } else {
            if (y != 0)
                file2d[y - 1][x] = readfile[z];
            x++;
        }
    }
    return file2d;
}