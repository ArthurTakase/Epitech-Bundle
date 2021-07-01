/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** remove_from_line
*/

#include "match.h"
#include "lib.h"

void remove_from_line(match_t *match, int line, int matche)
{
    int len = my_strlen(match->map[line]);
    int temp_matche = matche;

    for (int i = len; matche != 0; i--) {
        if (match->map[line][i] == '|') {
            match->map[line][i] = ' ';
            matche--;
        }
    }
    match->all_sticks -= temp_matche;
}