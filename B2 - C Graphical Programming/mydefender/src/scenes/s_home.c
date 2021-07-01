/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** s_home
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

void init_game(defender_t *def)
{
    sfIntRect *rect = &def->sprites->life->rect;

    def->tower = clear_list(def->tower);
    def->trap = clear_list(def->trap);
    def->money->value = MONEY_BASE;
    def->money->txt_char = my_itos(def->money->value, 10);
    sfText_setString(def->money->txt, def->money->txt_char);
    free(def->money->txt_char);
    free(def->waves);
    def->current_wave = 0;
    def->waves = init_wave(def);
    for (int i = 0; i < 6; ++i)
        sfSprite_setScale(def->arr_z[i]->sprite, (sfVector2f){1, 1});
    def->life = 3;
    rect->top = 0;
    sfSprite_setTextureRect(def->sprites->life->sprite, *rect);
    go_to(def, GAME);
}

void home_btn(defender_t *def, sfEvent event)
{
    if (event.mouseButton.button == sfMouseLeft) {
        if (event.type == sfEvtMouseButtonReleased) {
            if (check_button(def, (btn_t) {397, 406, 150, 40}))
                init_game(def);
            if (check_button(def, (btn_t) {397, 455, 150, 40}))
                go_to(def, EXIT);
            if (check_button(def, (btn_t) {905, 7, 45, 45}))
                go_to(def, SETTINGS);
            if (check_button(def, (btn_t) {908, 57, 38, 47}))
                go_to(def, HOW);
            check_click(def->sprites->btn_start, 0);
            check_click(def->sprites->btn_exit, 0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (check_button(def, (btn_t) {397, 406, 150, 40}))
                check_click(def->sprites->btn_start, 152);
            if (check_button(def, (btn_t) {397, 455, 150, 40}))
                check_click(def->sprites->btn_exit, 152);
        }
    }
}

void home_event(defender_t *def)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(def->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(def->window);
        check_hover(def, def->sprites->btn_exit->sprite,
                    (btn_t) {397, 455, 150, 40});
        check_hover(def, def->sprites->btn_start->sprite,
                    (btn_t) {397, 406, 150, 40});
        home_btn(def, event);
    }
}

void draw_home(defender_t *def)
{
    all_sprite_t *spr = def->sprites;

    spr->btn_exit->pos = (sfVector2f){397, 455};
    sfSprite_setPosition(spr->btn_exit->sprite, spr->btn_exit->pos);
    sfRenderWindow_clear(def->window, sfBlack);
    restart_other_clock(def);
    sfRenderWindow_drawSprite(def->window, spr->home->sprite, NULL);
    sfRenderWindow_drawSprite(def->window, spr->btn_exit->sprite, NULL);
    sfRenderWindow_drawSprite(def->window, spr->btn_start->sprite, NULL);
    move_cursor(def);
}

void home(defender_t *defender)
{
    home_event(defender);
    draw_home(defender);
    sfRenderWindow_display(defender->window);
}