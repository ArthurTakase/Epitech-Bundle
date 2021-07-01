/*
** EPITECH PROJECT, 2020
** paralax
** File description:
** event
*/

#include "struct.h"

void analyse_event(run_t *run, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(run->window);
    if (sfKeyboard_isKeyPressed(sfKeySpace) && run->player->is_jump == 0) {
        sfSound_play(run->sound->jump->sound);
        run->player->is_jump = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        run->is_over = PAUSE;
}

void event_all(run_t *run)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(run->window, &event))
        analyse_event(run, event);
}