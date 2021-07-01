/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** gen
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "dante.h"
#include "lib.h"

void set_imperfect(gen_t *gen)
{
    int x;
    int y;

    for (int i = 0; i < gen->line; i++) {
        if (((gen->col / 2) - 1) * 2 + 1 == 0 ||
            ((gen->line / 2) - 1) * 2 + 1 == 0)
            continue;
        x = rand() % (((gen->col / 2) - 1) * 2 + 1);
        y = rand() % (((gen->line / 2) - 1) * 2 + 1);
        if (gen->map[y][x] == 'X')
            gen->map[y][x] = '1';
    }
}

int gen_laby(gen_t *gen)
{
    pos_t pos;

    pos.x = 0;
    pos.y = 0;
    gen->nb_zero = 0;
    gen->map = first_gen(gen);
    if (gen->map == NULL)
        return RETURN_ERROR;
    srand(time(NULL));
    while (!is_end(gen)) {
        if (check_every_dir(gen, &pos) && !is_end(gen))
            new_way(gen, &pos);
        move(gen, &pos);
    }
    return RETURN_SUCCES;
}