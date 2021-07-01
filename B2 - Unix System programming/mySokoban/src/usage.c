/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** usage
*/

#include "lib.h"
#include <stdlib.h>

void print_usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("map file representing the warehouse map, containing '#' for");
    my_putstr("walls, 'P' for the player, 'X' for boxes");
    my_putstr(" and 'O' for storage locations.\n");
}

void usage(int argc, char **argv)
{
    for (int i = 0; i != argc; i++)
        if (!my_strcmp(argv[i], "-h")) {
            print_usage();
            exit(0);
        }
}