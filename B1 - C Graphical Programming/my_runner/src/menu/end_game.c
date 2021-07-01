/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** defeat
*/

#include "struct.h"

void event_end(run_t *run)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(run->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(run->window);
        if (sfMouse_isButtonPressed(0)) {
            start_game(run, (button_t){446, 346, 67, 137}, GAME);
            start_game(run, (button_t){444, 417, 56, 130}, MENU);
        }
    }
}

void menu_end(run_t *run, sprite_t *sprite)
{
    draw_all(run);
    animation(run);
    move_fps(run);
    jump(run);
    sfRenderWindow_drawSprite(run->window, sprite->sprite, NULL);
    sfText_setPosition(run->score->txt, (sfVector2f){120, 20});
    sfRenderWindow_drawText(run->window, run->score->txt, NULL);
    sfRenderWindow_drawText(run->window, run->best->txt, NULL);
    move_cursor(run);
    sfRenderWindow_drawSprite(run->window, run->filtre->sprite, NULL);
    sfRenderWindow_display(run->window);
}

void end_game(run_t *run)
{
    sfSound_setVolume(run->sound->footstep->sound, 0.0);
    event_end(run);
    check_best(run);
    if (run->is_over == DEFEAT) {
        sfSprite_setScale(run->player->sprite, (sfVector2f){0, 0});
        menu_end(run, run->menu->defeat_1);
    }
    if (run->is_over == VICTORY)
        menu_end(run, run->menu->win_1);
}