/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** end
*/

#include "generator.h"

int is_end(gen_t *gen)
{
    if (gen->nb_zero == 1 && gen->map[gen->line - 1][gen->col - 1] == '0') {
        gen->map[gen->line - 1][gen->col - 1] = '1';
        if (gen->col > 1)
            gen->map[gen->line - 1][gen->col - 2] = '1';
        else if (gen->line > 1)
            gen->map[gen->line - 2][gen->col - 1] = '1';
        gen->nb_zero -= 1;
    }
    if (gen->nb_zero == 0)
        return TRUE;
    return FALSE;
}