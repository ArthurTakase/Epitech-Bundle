/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event
*/

#include "rpg.h"

void end_fight_event_part(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfMouse_isButtonPressed(0))
        rpg->sprites->chest->state = 1;
}

void end_fight_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event))
        end_fight_event_part(rpg, &event);
}