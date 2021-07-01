/*
** EPITECH PROJECT, 2021
** Usage
** File description:
** usage
*/

#include <stdio.h>
#include <string.h>
#include "my_maccro.h"

static void print_usage(void)
{
    printf("To use the solver properly you should type :\n\n  \
'./solver [FILE]'\n\nWhere [FILE] contains a maze only with 'X' \
as walls and '*' as free space.\n");
}

int display_usage(int ac, const char **av)
{
    if (ac == 2 && !strcmp("-h", av[1])) {
        print_usage();
        return (EPITECH_ERROR);
    }
    return (MY_EXIT_SUCCESS);
}
