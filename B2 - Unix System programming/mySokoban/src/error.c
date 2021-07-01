/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** error
*/

#include <stdio.h>
#include "lib.h"

int how_many(char letter, char *src)
{
    int nbr = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == letter)
            nbr++;
    }
    return nbr;
}

int check_char(char *file)
{
    char good[7] = {' ', '\n', '#', 'X', 'O', 'P', 0};

    for (int i = 0; file[i] != '\0'; i++)
        if (!my_in(file[i], good))
            return 1;
    return 0;
}

int get_error(int argc, char **argv)
{
    FILE *file;
    char *read_file;

    if (argc != 2)
        return 1;
    if ((file = fopen(argv[1], "r")) == NULL)
        return 1;
    fclose(file);
    read_file = load_file(argv[1]);
    if (how_many('O', read_file) == 0)
        return 1;
    if (how_many('O', read_file) != how_many('X', read_file))
        return 1;
    if (check_char(read_file))
        return 1;
    return 0;
}