/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** s_pause
*/

#include "defender.h"
#include "lib.h"

void pause_btn(defender_t *def, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonReleased) {
        if (check_button(def, (btn_t) {578, 151, 22, 22}))
            go_to(def, GAME);
        if (check_button(def, (btn_t) {404, 231, 150, 40}))
            go_to(def, HOME);
        if (check_button(def, (btn_t) {404, 284, 150, 40}))
            go_to(def, EXIT);
        check_click(def->sprites->btn_menu, 0);
        check_click(def->sprites->btn_exit, 0);
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (check_button(def, (btn_t) {404, 231, 150, 40}))
            check_click(def->sprites->btn_menu, 152);
        if (check_button(def, (btn_t) {404, 284, 150, 40}))
            check_click(def->sprites->btn_exit, 152);
    }
}

void pause_event(defender_t *def, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(def->window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        def->scene = GAME;
    check_hover(def, def->sprites->btn_exit->sprite,
                (btn_t){404, 284, 150, 40});
    check_hover(def, def->sprites->btn_menu->sprite,
                (btn_t){404, 231, 150, 40});
    if (event->mouseButton.button == sfMouseLeft)
        pause_btn(def, event);
}

void draw_pause(defender_t *def)
{
    all_sprite_t *spr = def->sprites;

    spr->btn_exit->pos = (sfVector2f){404, 284};
    sfSprite_setPosition(spr->btn_exit->sprite, spr->btn_exit->pos);
    spr->btn_exit->pos = (sfVector2f){404, 231};
    sfSprite_setPosition(spr->btn_menu->sprite, spr->btn_menu->pos);
    sfRenderWindow_clear(def->window, sfBlack);
    draw_all(def);
    sfRenderWindow_drawSprite(def->window, def->sprites->life->sprite, NULL);
    sfRenderWindow_drawText(def->window, def->money->txt, NULL);
    sfRenderWindow_drawText(def->window, def->enn_left->txt, NULL);
    restart_other_clock(def);
    sfRenderWindow_drawSprite(def->window, spr->pause->sprite, NULL);
    sfRenderWindow_drawSprite(def->window, spr->btn_exit->sprite, NULL);
    sfRenderWindow_drawSprite(def->window, spr->btn_menu->sprite, NULL);
    move_cursor(def);
}

void s_pause(defender_t *def)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(def->window, &event))
        pause_event(def, &event);
    draw_pause(def);
    sfRenderWindow_display(def->window);
}