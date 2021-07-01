/*
** EPITECH PROJECT, 2020
** paralax
** File description:
** main
*/

#include "struct.h"

void init(run_t *run)
{
    init_window(run);
    init_char(run);
    init_sound(run);
    init_all_clock(run);
    init_cursor(run);
    init_filtre(run);
    init_best(run);
    run->is_over = MENU;
}

int game(run_t *run)
{
    while (sfRenderWindow_isOpen(run->window)) {
        if (run->is_over == MENU)
            level_menu(run);
        if (run->is_over == GAME)
            game_loop(run);
        if (run->is_over == VICTORY || run->is_over == DEFEAT)
            end_game(run);
        if (run->is_over == PAUSE)
            pause_game(run);
    }
    destroy(run);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            return help();
        else
            return options(argv);
    }
    my_putstr("Please use -h for usage.\n");
    return 0;
}