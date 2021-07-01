/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** s_settings
*/

#include "defender.h"
#include "lib.h"

void check_sett(defender_t *def)
{
    if (check_button(def, (btn_t){7, 7, 38, 38}))
        go_to(def, HOME);
    if (check_button(def, (btn_t){456, 270, 50, 40}))
        set_volume(def);
    if (check_button(def, (btn_t){458, 351, 41, 41}))
        set_fullscreen(def);
    if (check_button(def, (btn_t){431, 196, 95, 40}))
        set_fps(def);
}

void sett_event(defender_t *defender)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(defender->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(defender->window);
        if (sfMouse_isButtonPressed(0))
            check_sett(defender);
    }
}

void settings(defender_t *def)
{
    all_sprite_t *spr = def->sprites;

    sett_event(def);
    sfRenderWindow_clear(def->window, sfBlack);
    restart_other_clock(def);
    sfRenderWindow_drawSprite(def->window, spr->sett->sprite, NULL);
    sfRenderWindow_drawSprite(def->window, spr->sound->sprite, NULL);
    sfRenderWindow_drawSprite(def->window, spr->screen->sprite, NULL);
    sfRenderWindow_drawText(def->window, def->fps->txt, NULL);
    move_cursor(def);
    sfRenderWindow_display(def->window);
}