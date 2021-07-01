/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** draw
*/

#include "defender.h"

void move_cursor(defender_t *def)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(def->window);
    sprite_t *mouse = def->sprites->mouse;

    mouse->pos.x = mouse_pos.x;
    mouse->pos.y = mouse_pos.y;
    sfSprite_setPosition(mouse->sprite, mouse->pos);
    sfRenderWindow_drawSprite(def->window, mouse->sprite, NULL);
}

void move_all(defender_t *def)
{
    sprite_t *arr_sprt[0] = {};
    sfClock *dclock = def->clocks->dt_game->clock;
    float dtime = sfTime_asMilliseconds(sfClock_getElapsedTime(dclock));
    sfVector2f new;
    trap_t temp = def->trap;

    for (int i = 0; i < 0; ++i) {
        new.x = arr_sprt[i]->move.x * dtime;
        new.y = arr_sprt[i]->move.y * dtime;
        sfSprite_move(arr_sprt[i]->sprite, new);
    }
    while (temp != NULL) {
        new.x = temp->trap->move.x * dtime;
        new.y = temp->trap->move.y * dtime;
        sfSprite_move(temp->trap->sprite, new);
        temp = temp->next;
    }
    sfClock_restart(def->clocks->dt_game->clock);
}

void draw_all(defender_t *def)
{
    sprite_t *arr_sprt[8] = {def->sprites->map, def->sprites->ui,
                def->zones->zone1, def->zones->zone2, def->zones->zone3, 
                def->zones->zone4, def->zones->zone5, def->zones->zone6};
    trap_t temp = def->trap;
    trap_t temp2 = def->tower;
    sfRenderWindow *win = def->window;

    for (int i = 0; i < 8; ++i)
        sfRenderWindow_drawSprite(win, arr_sprt[i]->sprite, NULL);
    while (temp != NULL) {
        if (temp->trap->is_kill == OFF)
            sfRenderWindow_drawSprite(win, temp->trap->sprite, NULL);
        temp = temp->next;
    }
    while (temp2 != NULL) {
        sfRenderWindow_drawSprite(win, temp2->trap->sprite, NULL);
        temp2 = temp2->next;
    }
}