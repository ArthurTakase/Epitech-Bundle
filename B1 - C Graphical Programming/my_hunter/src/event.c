/*
** EPITECH PROJECT, 2020
** My_Hunter
** File description:
** event
*/

#include "../include/csfml.h"

void check_bird_colider(data_t *data);

void check_dog_colider(data_t *data);

void init(data_t *data);

void analyse_event(data_t *data, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(data->window);
    if (data->isStart) {
        if (event.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == 0) {
            check_dog_colider(data);
            check_bird_colider(data);
        }
    } else if (event.type == sfEvtMouseButtonPressed ||
        event.type == sfEvtKeyReleased)
        data->isStart = 1;
}