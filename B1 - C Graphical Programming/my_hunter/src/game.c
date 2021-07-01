/*
** EPITECH PROJECT, 2020
** My_Hunter
** File description:
** game
*/

#include "../include/csfml.h"

void analyse_event(data_t *data, sfEvent event);

void draw_all(data_t *data);

void anim_all(data_t *data);

void game(data_t *data)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfTime time;

    while (sfRenderWindow_isOpen(data->window)) {
        while (sfRenderWindow_pollEvent(data->window, &event))
            analyse_event(data, event);
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds / 1000000.0 > 0.2) {
            anim_all(data);
            sfClock_restart(clock);
        }
        if (data->isStart)
            draw_all(data);
        else
            sfRenderWindow_drawSprite(data->window, data->menu->sprite, NULL);
        sfRenderWindow_display(data->window);
    }
}