/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** matchstick
*/

#include "match.h"
#include "lib.h"

int get_error(int argc, char **argv, match_t *match)
{
    if (argc != 3)
        return 1;
    if (!my_str_isnum(argv[1]) || !my_str_isnum(argv[2]))
        return 1;
    match->arg1 = my_getnbr(argv[1]);
    match->arg2 = my_getnbr(argv[2]);
    if (match->arg1 >= 100 || match->arg1 <= 1)
        return 1;
    if (match->arg2 <= 0)
        return 1;
    match->all_sticks = 1;
    match->line = -1;
    match->matche = -1;
    match->winner = 0;
    return 0;
}

void reset(match_t *match)
{
    if (match->winner == IA)
        free(match->get_line);
    match->line = -1;
    match->matche = -1;
}

int loop(match_t *match)
{
    while (match->all_sticks != 0) {
        print_map(match);
        if (player_turn(match))
            return 1;
        reset(match);
        if (match->all_sticks == 0)
            break;
        print_map(match);
        if (ia_turn(match))
            return 1;
        reset(match);
    }
    return 0;
}

int matchstick(int argc, char **argv)
{
    match_t match;

    if (get_error(argc, argv, &match))
        return 84;
    calcul_map(&match);
    create_map(&match);
    if (loop(&match))
        return 0;
    print_map(&match);
    free(match.infos);
    if (match.winner == IA)
        my_putstr("You lost, too bad...\n");
    else
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    return match.winner;
}