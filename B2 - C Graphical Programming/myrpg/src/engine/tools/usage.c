/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** usage
*/

#include "lib.h"
#include <stdlib.h>

int check_usage(char **argv)
{
    for (int i = 0; argv[i] != NULL; i++)
        if (!my_strcmp(argv[i], "-h"))
            return 1;
    return 0;
}

int help(void)
{
    my_putstr("\033[0;34mUSAGE\033[0m\n"
            "./my_rpg [-h]\n\n"
            "\33[0;34mDESCRIPTION\033[0m\n"
            "N.C.\n\n"
            "\033[0;34mCONTROLS\033[0m\n"
            "N.C.\n");
    return 0;
}