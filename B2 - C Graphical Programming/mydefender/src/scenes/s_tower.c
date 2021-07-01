/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** s_tower
*/

#include "defender.h"
#include "lib.h"
#include <stdlib.h>

sprite_t *new_tower(sfIntRect rect, sfVector2f pos, stat_t stat)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/tower.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->att = stat.att;
    sprite->speed = stat.speed;
    sprite->timer = init_clock(stat.timer);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

void set_tower(int left, defender_t *def, int money, stat_t stat)
{
    sfIntRect tower = (sfIntRect){left, 0, 48, 82};
    sfSprite *current_zone = def->arr_z[def->current_zone]->sprite;
    sfVector2f coord = sfSprite_getPosition(current_zone);

    sfSound_play(def->sounds->click->sound);
    set_money(def, -money);
    def->tower = push_back_list(def->tower, new_tower(tower,
                (sfVector2f){coord.x + 3, coord.y - 57}, stat));
    sfSprite_setScale(current_zone, (sfVector2f){0, 0});
    sfSound_play(def->sounds->build->sound);
}

void get_tower(defender_t *def)
{
    int money = def->money->value;

    if (check_button(def, (btn_t){361, 469, 54, 59}) && money >= 10)
        set_tower(0, def, 10, (stat_t){1, 0, 1, 1.0});
    if (check_button(def, (btn_t){416, 469, 54, 59}) && money >= 20)
        set_tower(48, def, 20, (stat_t){0, 0, 0.5, 0});
    if (check_button(def, (btn_t){470, 469, 54, 59}) && money >= 30)
        set_tower(144, def, 30, (stat_t){4, 0, 1, 2.0});
    if (check_button(def, (btn_t){524, 469, 54, 59}) && money >= 50)
        set_tower(96, def, 50, (stat_t){1, 0, 0.75, 2});
    def->scene = GAME;
}

void tower_event(defender_t *def)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(def->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(def->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            def->scene = PAUSE;
        if (sfMouse_isButtonPressed(0))
            get_tower(def);
    }
}

void tower(defender_t *def)
{
    collider(def);
    delet_trap(def);
    tower_event(def);
    animation(def);
    move_all(def);
    move_enn(def);
    restart_other_clock(def);
    draw_all(def);
    sfRenderWindow_drawText(def->window, def->enn_left->txt, NULL);
    draw_sprite(def, def->sprites->hud);
    draw_sprite(def, def->sprites->life);
    if (def->waves->alive == 0)
        draw_sprite(def, def->sprites->wave);
    move_cursor(def);
    hover_tower(def);
    sfRenderWindow_drawText(def->window, def->money->txt, NULL);
    sfRenderWindow_display(def->window);
}