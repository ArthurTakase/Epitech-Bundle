/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** line
*/

#include "match.h"
#include "lib.h"

int get_line(match_t *match)
{
    do {
        my_putstr("Line: ");
        if (my_getline(match))
            return 1;
        if (!my_str_isnum(match->get_line)) {
            my_putstr("Error: invalid input (positive number expected)\n");
            continue;
        }
        match->line = my_getnbr(match->get_line);
        if (match->line < 1 || match->line > match->infos->nb_line - 2) {
            my_putstr("Error: this line is out of range\n");
            match->line = -1;
        }
    } while (match->line == -1);
    return 0;
}