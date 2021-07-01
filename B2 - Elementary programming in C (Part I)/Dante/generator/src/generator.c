/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** generator
*/

#include <stdlib.h>
#include <time.h>
#include "generator.h"
#include "dante.h"
#include "lib.h"

int get_error(int argc, char **argv, gen_t *gen)
{
    if (argc < 3 || argc > 4)
        return RETURN_ERROR;
    if (!my_str_isnum(argv[1]) || !my_str_isnum(argv[2]))
        return RETURN_ERROR;
    if (argc == 4 && my_strcmp(argv[3], "perfect"))
        return RETURN_ERROR;
    gen->type = IMPERFECT;
    if (argc == 4 && !my_strcmp(argv[3], "perfect"))
        gen->type = PERFECT;
    gen->col = my_getnbr(argv[1]);
    gen->line = my_getnbr(argv[2]);
    return RETURN_SUCCES;
}

int check_every_dir(gen_t *gen, pos_t *pos)
{
    if (!check_move(gen, pos, UP) &&
        !check_move(gen, pos, DOWN) &&
        !check_move(gen, pos, LEFT) &&
        !check_move(gen, pos, RIGHT))
        return TRUE;
    return FALSE;
}

void print_laby(gen_t *gen)
{
    for (int y = 0; y < gen->line; y++) {
        for (int x = 0; x < gen->col; x++) {
            if (gen->map[y][x] == '1')
                printf("*");
            else
                printf("X");
        }
        if (y != gen->line - 1)
            printf("\n");
    }
}

int generator(int argc, char **argv)
{
    gen_t gen;

    if (get_error(argc, argv, &gen))
        return EXIT_ERROR;
    if (gen_laby(&gen))
        return EXIT_ERROR;
    if (gen.type == IMPERFECT)
        set_imperfect(&gen);
    print_laby(&gen);
    for (int i = 0; i < gen.line + 1; i++)
        free(gen.map[i]);
    free(gen.map);
    return EXIT_SUCCESS;
}