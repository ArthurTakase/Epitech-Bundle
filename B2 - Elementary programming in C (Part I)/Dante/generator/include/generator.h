/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdio.h>

#define IMPERFECT 0
#define PERFECT 1

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define TRUE 1
#define FALSE 0

#define EXIT_ERROR 84
#define RETURN_ERROR 1
#define RETURN_SUCCES 0

typedef struct s_gen
{
    int line;
    int col;
    char **map;
    int type;
    int nb_zero;
} gen_t;

typedef struct s_pos
{
    int x;
    int y;
} pos_t;

int generator(int argc, char **argv);
char **first_gen(gen_t *gen);
int is_end(gen_t *gen);
void move(gen_t *gen, pos_t *pos);
int check_move(gen_t *gen, pos_t *pos, int dir);
int check_every_dir(gen_t *gen, pos_t *pos);
void new_way(gen_t *gen, pos_t *pos);
int gen_laby(gen_t *gen);
void set_imperfect(gen_t *gen);

#endif /* !GENERATOR_H_ */
