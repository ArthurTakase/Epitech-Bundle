/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event
*/

#include "rpg.h"

void left_click_options(rpg_t *rpg)
{
    if (is_over(rpg, (btn_t){265, 147, 118, 61}))
        use_potion(rpg);
    if (is_over(rpg, (btn_t){71, 11, 47, 47}))
        sfRenderWindow_close(rpg->window);
    if (is_over(rpg, (btn_t){11, 8, 47, 47})) {
        switch_music(rpg, "home_music.ogg");
        rpg->scene = HOME;
    }
}

void right_click_options(rpg_t *rpg)
{
    if (is_over(rpg, (btn_t){265, 147, 118, 61}))
        buy_potion(rpg);
}

void inventory_event_part(rpg_t *rpg, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (rpg->fight == NULL)
            rpg->scene = GAME;
        else
            rpg->scene = FIGHT;
    }
    if (event->type == sfEvtMouseButtonReleased) {
        if (event->mouseButton.button == sfMouseLeft)
            left_click_options(rpg);
        if (event->mouseButton.button == sfMouseRight)
            right_click_options(rpg);
    }
}

void inventory_event(rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(rpg->window, &event))
        inventory_event_part(rpg, &event);
}