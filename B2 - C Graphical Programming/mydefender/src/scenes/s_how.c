/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** s_how
*/

#include "defender.h"
#include "lib.h"

void how_event(defender_t *defender, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(defender->window);
    if (sfMouse_isButtonPressed(0))
        if (check_button(defender, (btn_t){7, 7, 38, 38}))
            go_to(defender, HOME);
}

void how(defender_t *def)
{
    all_sprite_t *spr = def->sprites;
    sfEvent event;

    while (sfRenderWindow_pollEvent(def->window, &event))
        how_event(def, &event);
    sfRenderWindow_clear(def->window, sfBlack);
    restart_other_clock(def);
    sfRenderWindow_drawSprite(def->window, spr->how->sprite, NULL);
    move_cursor(def);
    sfRenderWindow_display(def->window);
}