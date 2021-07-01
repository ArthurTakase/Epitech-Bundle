/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** change_fps
*/

#include "struct.h"

void to_trente(run_t *run, button_t coord)
{
    if (check_button(run, coord)) {
        run->menu->current_fps = run->menu->cc_1->sprite;
        run->option->fps = 30;
        sfRenderWindow_setFramerateLimit(run->window, 30);
        sfSound_play(run->sound->button->sound);
    }
}

void to_soixante(run_t *run, button_t coord)
{
    if (check_button(run, coord)) {
        run->menu->current_fps = run->menu->cc_2->sprite;
        run->option->fps = 60;
        sfRenderWindow_setFramerateLimit(run->window, 60);
        sfSound_play(run->sound->button->sound);
    }
}