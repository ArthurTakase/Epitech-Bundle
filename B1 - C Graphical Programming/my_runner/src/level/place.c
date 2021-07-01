/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** place
*/

#include "struct.h"

void new_trap(run_t *run, char value, int start)
{
    if (value == '0')
        run->trap = push_back_list(run->trap, init_trap_1(start));
    if (value == '1')
        run->trap = push_back_list(run->trap, init_trap_2(start));
    if (value == '2')
        run->trap = push_back_list(run->trap, init_trap_3(start));
    if (value == '3')
        run->trap = push_back_list(run->trap, init_flag(start));
    if (value == '.')
        run->trap = push_back_list(run->trap, init_void(start));
}

void delet_trap(run_t *run)
{
    if (is_empty_list(run->trap))
        return;
    if (sfSprite_getPosition(run->trap->trap->sprite).x < -100) {
        sfSprite_destroy(run->trap->trap->sprite);
        run->trap = pop_front_list(run->trap);
    }
}

void place_level(run_t *run, char *level)
{
    int pos;
    srand(time(NULL));

    run->len_trap = 0;
    for (int i = 0; level[i] != '!'; i++) {
        run->len_trap += 1;
        if (rand() % 10 == 0) {
            pos = DIM_X + (80 * i) + ((rand() % 80) - 80 / 2);
            run->trap = push_back_list(run->trap, init_trap_coin(pos));
        }
        new_trap(run, level[i], DIM_X + (80 * i));
    }
    run->trap_max = run->len_trap;
}