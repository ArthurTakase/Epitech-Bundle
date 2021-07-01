/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** defender
*/

#include "lib.h"
#include "rpg.h"

int check_error(int argc, char **argv, char **env)
{
    argc = argc;
    argv = argv;
    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], "DISPLAY="))
            return 0;
    return 1;
}

int my_rpg(int argc, char **argv, char **env)
{
    rpg_t rpg;

    randomize();
    if (check_usage(argv))
        return help();
    if (check_error(argc, argv, env))
        return 84;
    init(&rpg, argc, argv);
    gameloop(&rpg);
    return 0;
}