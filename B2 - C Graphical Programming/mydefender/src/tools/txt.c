/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** txt
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

void set_money(defender_t *def, int new)
{
    char *new_money;

    def->money->value += new;
    new_money = my_itos(def->money->value, 10);
    sfText_setString(def->money->txt, new_money);
    if (def->money->value != 0)
        free(new_money);
}

void set_wave_value(defender_t *def)
{
    char *new_wave_value;

    def->waves->alive -= 1;
    new_wave_value = my_itos(def->waves->alive, 10);
    sfText_setString(def->enn_left->txt, new_wave_value);
    if (def->waves->alive != 0)
        free(new_wave_value);
}