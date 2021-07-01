/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event
*/

#include "rpg.h"

void map_event_part(rpg_t *rpg, sfEvent *event, map_t *m)
{
    if (event->type == sfEvtClosed) {
        m->state = 0;
        sfRenderWindow_close(rpg->window);
    }
    if (event->type == sfEvtKeyPressed)
        movement(rpg, &event->key, m);
    if (event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseLeft)
        handle_click(event->mouseButton, m);
    if (event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseRight)
        handle_click_remove(event->mouseButton, m);
}

void map_event(rpg_t *rpg, map_t *m)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event)) {
        map_event_part(rpg, &event, m);
    }
}