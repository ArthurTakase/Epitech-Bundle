/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** option
*/

#include "struct.h"

int options(char **argv)
{
    run_t *run = malloc(sizeof(run_t));
    run->option = malloc(sizeof(option_t));

    if (check_file(argv[1]))
        return 84;
    run->option->fps = 30;
    init(run);
    init_ui(run);
    init_score(run);
    init_menu(run);
    init_jauge(run);
    run->option->level = "asset/img/lvl2/";
    init_background(run);
    run->map = load_file(argv[1]);
    return game(run);
}