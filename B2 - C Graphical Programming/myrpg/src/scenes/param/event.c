/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** event
*/

#include "rpg.h"
#include "lib.h"

void param_event_part(rpg_t *rpg, sfEvent *event, int param)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        rpg->scene = HOME;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (param == 0)
            set_volume(rpg);
        if (param == 1)
            set_fps(rpg, 10, 'p');
    }
    if (sfMouse_isButtonPressed(sfMouseRight) && param == 1)
        set_fps(rpg, 10, 'm');
}

void param_event(rpg_t *rpg, int param)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        param_event_part(rpg, &event, param);
    }
}