/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** main
*/

#include "../include/my.h"
#include "../include/tools.h"

// Function that launches the others
int start(char *argv)
{
    char *readfile = load_file_in_mem(argv);
    int y = height(readfile);
    int x = width(readfile, y);
    char **map = load_2d_arr_from_file(readfile, y, x);
    int **dup = create_dup(map, y, x);

    dup = set_dup(dup, y, x);
    map = print_x(dup, map, y, x);
    for (int i = 0; i < y - 1; i++) {
        my_putstr(map[i]);
        line();
    }
    return 0;
}