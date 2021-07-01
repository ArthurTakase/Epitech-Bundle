/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_window
*/

#include "defender.h"

void init_window(defender_t *def)
{
    sfVideoMode mode;

    if (def->is_full == OFF) {
        mode = (sfVideoMode){960, 540, 32};
        def->window = sfRenderWindow_create(mode, "My_Defender", 7, NULL);
    } else {
        mode = (sfVideoMode){1920, 1080, 32};
        def->window = sfRenderWindow_create(mode, "My_Defender", 8, NULL);
    }
    sfRenderWindow_setFramerateLimit(def->window, FPS);
    sfRenderWindow_setMouseCursorVisible(def->window, sfFalse);
}