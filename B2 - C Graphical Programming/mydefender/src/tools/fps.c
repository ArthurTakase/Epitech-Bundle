/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** fps
*/

#include "defender.h"

void set_fps(defender_t *def)
{
    int new_fps;
    char *new;

    switch (def->fps->value) {
        case 30:
            new_fps = 60;
            new = "60";
            break;
        case 60:
            new_fps = 120;
            new = "120";
            break;
        default:
            new_fps = 30;
            new = "30";
            break;
    }
    sfText_setString(def->fps->txt, new);
    sfRenderWindow_setFramerateLimit(def->window, new_fps);
    def->fps->value = new_fps;
}