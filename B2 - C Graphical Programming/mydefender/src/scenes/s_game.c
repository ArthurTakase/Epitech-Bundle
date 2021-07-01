/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** s_game
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

int check_zone(defender_t *def)
{
    sfFloatRect z;
    sfFloatRect m = sfSprite_getGlobalBounds(def->sprites->mouse->sprite);

    for (int i = 0; i < 6; ++i) {
        z = sfSprite_getGlobalBounds(def->arr_z[i]->sprite);
        if (sfFloatRect_intersects(&m, &z, NULL)) {
            def->current_zone = i;
            sfSound_play(def->sounds->click->sound);
            return i;
        }
    }
    return -1;
}

void game_event_part(defender_t *def)
{
    if (sfMouse_isButtonPressed(0)) {
        if (check_button(def, (btn_t){344, 50, 271, 36}) &&
            def->waves->alive == 0) {
            def->current_wave += 1;
            free(def->waves);
            def->waves = init_wave(def);
        } else if (check_zone(def) != -1)
            def->scene = TOWER;
    }
}

void game_event(defender_t *def)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(def->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(def->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            def->scene = PAUSE;
        game_event_part(def);
    }
}

void game(defender_t *def)
{
    collider(def);
    delet_trap(def);
    game_event(def);
    animation(def);
    move_all(def);
    move_enn(def);
    restart_other_clock(def);
    draw_all(def);
    sfRenderWindow_drawText(def->window, def->money->txt, NULL);
    sfRenderWindow_drawText(def->window, def->enn_left->txt, NULL);
    draw_sprite(def, def->sprites->life);
    if (def->waves->alive == 0)
        draw_sprite(def, def->sprites->wave);
    move_cursor(def);
    sfRenderWindow_display(def->window);
}