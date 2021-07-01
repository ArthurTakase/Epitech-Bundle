/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** first_gen
*/

#include "dante.h"
#include "generator.h"

char gen_part(int x, int y, gen_t *gen)
{
    if (y == 0 && x == 0)
        return '1';
    if (y == gen->line - 1 && x == gen->col - 1) {
        gen->nb_zero += 1;
        return '0';
    }
    if (y % 2 == 0) {
        if (x % 2 != 0)
            return 'X';
        gen->nb_zero += 1;
        return '0';
    }
    return 'X';
}

char **first_gen(gen_t *gen)
{
    char **laby = alloc_laby(gen->line, gen->col);

    if (laby == NULL)
        return NULL;
    for (int y = 0; y < gen->line; y++)
        for (int x = 0; x < gen->col; x++)
            laby[y][x] = gen_part(x, y, gen);
    return laby;
}