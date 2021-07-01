/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** get_player
*/

#include "match.h"
#include "lib.h"

int player_turn(match_t *match)
{
    my_putstr("\nYour turn:\n");

    do {
        if (get_line(match))
            return 1;
        if (get_matche(match))
            return 1;
    } while (match->matche == -1);
    my_putstr("Player removed ");
    my_put_nbr(match->matche);
    my_putstr(" match(es) from line ");
    my_put_nbr(match->line);
    my_putstr("\n");
    match->winner = IA;
    remove_from_line(match, match->line, match->matche);
    return 0;
}