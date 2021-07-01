/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** matche
*/

#include "match.h"
#include "lib.h"

void check_matche(match_t *match)
{
    if (match->matche <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        match->matche = -1;
    }
    if (match->matche > match->arg2) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(match->arg2);
        my_putstr(" matches per turn\n");
        match->matche = -1;
    }
    if (how_many_in(match->map[match->line], '|') < match->matche) {
        my_putstr("Error: not enough matches on this line\n");
        match->matche = -1;
    }
}

int get_matche(match_t *match)
{
    my_putstr("Matches: ");
    if (my_getline(match))
        return 1;
    if (!my_str_isnum(match->get_line)) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 0;
    }
    match->matche = my_getnbr(match->get_line);
    check_matche(match);
    return 0;
}