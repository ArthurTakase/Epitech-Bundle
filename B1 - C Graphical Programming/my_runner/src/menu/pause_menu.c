/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** pause_menu
*/

#include "struct.h"

void event_pause(run_t *run)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(run->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(run->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            run->is_over = GAME;
    }
}

void pause_game(run_t *run)
{
    event_pause(run);
    draw_all(run);
    sfRenderWindow_drawText(run->window, run->menu->pause->txt, NULL);
    move_cursor(run);
    sfRenderWindow_drawSprite(run->window, run->filtre->sprite, NULL);
    sfRenderWindow_display(run->window);
}