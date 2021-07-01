/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** .h principal au programme
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <stdlib.h>

#define PLAYER 1
#define IA 2

typedef struct s_infos
{
    int lmax;
    int center;
    int nb_line;
    int nb_col;
} infos_t;

typedef struct s_match
{
    int all_sticks;
    char **map;
    char *get_line;
    int arg1;
    int arg2;
    infos_t *infos;
    int line;
    int matche;
    int winner;
} match_t;

void calcul_map(match_t *match);
void create_map(match_t *match);
void print_map(match_t *match);

int player_turn(match_t *match);
int get_line(match_t *match);
int get_matche(match_t *match);

int ia_turn(match_t *match);

void remove_from_line(match_t *match, int line, int matche);

int my_getline(match_t *match);

#endif