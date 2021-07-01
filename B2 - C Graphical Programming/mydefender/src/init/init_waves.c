/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_txt
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

waves_t *init_wave(defender_t *def)
{
    waves_t *wave = malloc(sizeof(waves_t));
    static int wave_value[7] = {3, 5, 7, 7, 9, 11, 20};
    char *current_value = my_itos(wave_value[def->current_wave], 10);

    wave->ennemies = wave_value[def->current_wave];
    wave->alive = wave_value[def->current_wave];
    wave->spawned = 0;
    sfText_setString(def->enn_left->txt, current_value);
    free(current_value);
    return wave;
}