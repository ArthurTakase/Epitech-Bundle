/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** fullscreen
*/

#include "defender.h"

void set_fullscreen(defender_t *def)
{
    switch (def->is_full) {
        case ON:
            def->is_full = OFF;
            break;
        case OFF:
            def->is_full = ON;
            break;
    }
    sfRenderWindow_destroy(def->window);
    init_window(def);
}