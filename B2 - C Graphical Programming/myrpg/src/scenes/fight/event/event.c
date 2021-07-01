/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event
*/

#include "rpg.h"
#include <stdlib.h>

void fight_event_part(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (rpg->fight->state == 0) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            go_to_inventory(rpg);
        else if (event->type == sfEvtKeyReleased)
            fight_menu(rpg, event);
    }
    else if (rpg->fight->state == 1 && event->type == sfEvtKeyReleased)
        select_ennemis_menu(rpg, event);
}

void fight_event(rpg_t *rpg)
{
    sfEvent event;
    sfVector2f mouse_pos = sfSprite_getPosition(rpg->sprites->mouse->sprite);

    if (mouse_pos.x < 0)
        reset_menu(rpg);
    while (sfRenderWindow_pollEvent(rpg->window, &event))
        fight_event_part(rpg, &event);
}