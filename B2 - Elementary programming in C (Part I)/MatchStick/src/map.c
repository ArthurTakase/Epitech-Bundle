/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-arthur.decaen
** File description:
** map
*/

#include "lib.h"
#include "match.h"

void alloc_map(match_t *match)
{
    char **map = malloc(sizeof(char *) * (match->infos->nb_line + 1));

    for (int i = 0; i < match->infos->nb_line + 1; i++)
        map[i] = malloc(sizeof(char) * (match->infos->nb_col + 1));
    match->map = map;
}

void calcul_map(match_t *match)
{
    infos_t *infos = malloc(sizeof(infos_t));

    infos->lmax = 2 * match->arg1 - 1;
    infos->center = match->arg1;
    infos->nb_line = match->arg1 + 2;
    infos->nb_col = infos->lmax + 2;
    match->infos = infos;
    alloc_map(match);
}

void create_map(match_t *match)
{
    static int stick = 1;
    int temp_stick;

    for (int y = 0; y < match->infos->nb_line; y++)
        for (int x = 0; x < match->infos->nb_col; x++)
            match->map[y][x] = '*';
    for (int y = 1; y < match->infos->nb_line - 1; y++) {
        temp_stick = stick;
        for (int x = 1; x < match->infos->nb_col - 1; x++) {
            match->map[y][x] = ' ';
            if (x > (match->infos->lmax / 2) - (stick / 2) && temp_stick != 0) {
                match->map[y][x] = '|';
                temp_stick--;
            }
        }
        stick += 2;
        match->all_sticks += stick;
    }
    match->all_sticks -= stick;
}

void print_map(match_t *match)
{
    for (int y = 0; y < match->infos->nb_line; y++) {
        my_putstr(match->map[y]);
        my_putstr("\n");
    }
}