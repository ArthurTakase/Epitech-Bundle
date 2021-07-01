/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** level_menu
*/

#include "struct.h"

int level_menu(run_t *run)
{
    level_event(run);
    draw_all(run);
    move_fps(run);
    animation(run);
    sfRenderWindow_drawSprite(run->window, run->menu->current_bg, NULL);
    sfRenderWindow_drawSprite(run->window, run->menu->current_fps, NULL);
    move_cursor(run);
    sfRenderWindow_drawSprite(run->window, run->filtre->sprite, NULL);
    sfRenderWindow_display(run->window);
}

void level_event(run_t *run)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(run->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(run->window);
        if (sfMouse_isButtonPressed(0)) {
            button(run, (button_t){194, 175, 150, 150}, "asset/img/lvl2/", 0);
            button(run, (button_t){349, 175, 150, 150}, "asset/img/lvl3/", 1);
            button(run, (button_t){505, 175, 150, 150}, "asset/img/lvl1/", 2);
            button(run, (button_t){661, 175, 150, 150}, "asset/img/lvl4/", 3);
            to_trente(run, (button_t){351, 342, 48, 140});
            to_soixante(run, (button_t){512, 342, 48, 140});
            start_game(run, (button_t){434, 410, 49, 125}, GAME);
        }
    }
}

void button(run_t *run, button_t coord, char *filepath, int index)
{
    sprite_t *arr_sprite[4] = {run->menu->level1, run->menu->level2,
                            run->menu->level3, run->menu->level4};

    if (check_button(run, coord)) {
        sfSound_play(run->sound->button->sound);
        run->option->level = filepath;
        init_background(run);
        run->menu->current_bg = arr_sprite[index]->sprite;
    }
}

void start_game(run_t *run, button_t coord, int where)
{
    if (check_button(run, coord)) {
        sfSound_play(run->sound->button->sound);
        sfSound_setVolume(run->sound->footstep->sound, 15.0);
        sfSprite_setScale(run->player->sprite, (sfVector2f){3, 3});
        init_ui(run);
        init_score(run);
        clear_trap(run);
        run->trap = new_list();
        if (where != MENU) {
            place_level(run, run->map);
            edit_jauge(run);
        }
        run->is_over = where;
    }
}