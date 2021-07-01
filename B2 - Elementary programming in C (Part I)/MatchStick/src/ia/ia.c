/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** ia
*/

#include "match.h"
#include "lib.h"
#include <time.h>

int ia_pickrandom(match_t *match)
{
    srand(time(NULL));
    do {
        do {
            match->line = (rand() % (match->infos->nb_line - 2)) + 1;
        } while (how_many_in(match->map[match->line], '|') < 1);
        match->matche = (rand() % (match->arg2 - 1) + 1);
    } while (how_many_in(match->map[match->line], '|') < match->matche);
    return 0;
}

int ia_one(match_t *match)
{
    int temp;

    srand(time(NULL));
    do {
        match->line = (rand() % (match->infos->nb_line - 2)) + 1;
    } while ((temp = how_many_in(match->map[match->line], '|')) < 1);
    for (int j = match->arg2; j != 0; j--) {
        if (j < temp) {
            match->matche = j;
            return 0;
        }
    }
    ia_pickrandom(match);
    return 0;
}

int ia_turn(match_t *match)
{
    my_putstr("\nAI's turn...\n");
    if (ia_one(match))
        return 1;
    my_putstr("AI removed ");
    my_put_nbr(match->matche);
    my_putstr(" match(es) from line ");
    my_put_nbr(match->line);
    my_putstr("\n");
    match->winner = PLAYER;
    remove_from_line(match, match->line, match->matche);
    return 0;
}