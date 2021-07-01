/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event
*/

#include "rpg.h"

void home_event_part(rpg_t *rpg, sfEvent *event, int scene)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (scene == 0) {
            switch_music(rpg, "music.ogg");
            rpg->scene = GAME;
        }
        if (scene == 1)
            rpg->scene = PARAM;
        if (scene == 2)
            sfRenderWindow_close(rpg->window);
    }
}

void home_event(rpg_t *rpg, int scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        home_event_part(rpg, &event, scene);
    }
}