/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** s_pause
*/

#include "defender.h"
#include "lib.h"

void win_btn(defender_t *def, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonReleased) {
        if (check_button(def, (btn_t) {497, 315, 150, 40}))
            go_to(def, HOME);
        if (check_button(def, (btn_t) {310, 315, 150, 40}))
            go_to(def, EXIT);
        check_click(def->sprites->btn_menu, 0);
        check_click(def->sprites->btn_exit, 0);
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if (check_button(def, (btn_t) {497, 315, 150, 40}))
            check_click(def->sprites->btn_menu, 152);
        if (check_button(def, (btn_t) {310, 315, 150, 40}))
            check_click(def->sprites->btn_exit, 152);
    }
}

void end_event(defender_t *def, sfEvent *event)
{
    

    if (event->type == sfEvtClosed)
        sfRenderWindow_close(def->window);
    check_hover(def, def->sprites->btn_exit->sprite,
                (btn_t){310, 315, 150, 40});
    check_hover(def, def->sprites->btn_menu->sprite,
                (btn_t){497, 315, 150, 40});
    if (event->mouseButton.button == sfMouseLeft)
        win_btn(def, event);
}

void draw_end(defender_t *def)
{
    all_sprite_t *spr = def->sprites;

    spr->btn_exit->pos = (sfVector2f){404, 284};
    sfSprite_setPosition(spr->btn_exit->sprite, spr->btn_exit->pos);
    sfRenderWindow_clear(def->window, sfBlack);
    draw_all(def);
    sfRenderWindow_drawText(def->window, def->money->txt, NULL);
    restart_other_clock(def);
    if (def->life == 0)
        sfRenderWindow_drawSprite(def->window, spr->lose->sprite, NULL);
    else
        sfRenderWindow_drawSprite(def->window, spr->win->sprite, NULL);
    sfSprite_setPosition(spr->btn_exit->sprite, (sfVector2f){310, 315});
    sfSprite_setPosition(spr->btn_menu->sprite, (sfVector2f){497, 315});
    sfRenderWindow_drawSprite(def->window, spr->btn_exit->sprite, NULL);
    sfRenderWindow_drawSprite(def->window, spr->btn_menu->sprite, NULL);
    sfText_setColor(def->score->txt, sfBlack);
    sfRenderWindow_drawText(def->window, def->score->txt, NULL);
    sfRenderWindow_drawText(def->window, def->enn_left->txt, NULL);
    move_cursor(def);
}

void end(defender_t *def)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(def->window, &event))
        end_event(def, &event);
    draw_end(def);
    sfRenderWindow_display(def->window);
}