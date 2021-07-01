/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** defender
*/

#include "lib.h"
#include "defender.h"

int check_usage(char **argv)
{
    for (int i = 0; argv[i] != NULL; i++)
        if (!my_strcmp(argv[i], "-h"))
            return 1;
    return 0;
}

int check_error(int argc, char **argv)
{
    argc = argc;
    argv = argv;
    return 0;
}

int my_defender(int argc, char **argv)
{
    defender_t defender;

    if (check_usage(argv))
        return help();
    if (check_error(argc, argv))
        return 84;
    init(&defender);
    gameloop(&defender);
    return 0;
}