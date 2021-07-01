/*
** EPITECH PROJECT, 2020
** My_Hunter
** File description:
** draw
*/

#include "../include/csfml.h"
#include "../include/my.h"

void check_duck_pos(sprite_t *duck);

void move_all(data_t *data)
{
    int pos_x = sfSprite_getPosition(data->dog->sprite).x;
    int new_x = (pos_x >= 620) ? 0 : pos_x + 10;
    float new_y = (10.0 / 5000.0) * ((pos_x - 310) * (pos_x - 310)) + 180;
    sfVector2f new_pose = {new_x, new_y};

    if (rand() % 60 == 1 && data->tv->rect.left != 2880)
        sfSound_play(data->sound->duck->sound);
    sfSprite_move(data->duck->sprite, data->duck->move);
    sfSprite_setPosition(data->dog->sprite, new_pose);
}

void move_cursor(data_t *data)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    data->cursor->pos.x = mouse_pos.x - 51.2 / 2;
    data->cursor->pos.y = mouse_pos.y - 51.2 / 2;
    sfSprite_setPosition(data->cursor->sprite, data->cursor->pos);
    sfRenderWindow_drawSprite(data->window, data->cursor->sprite, NULL);
}

void draw_all(data_t *data)
{
    sfRenderWindow_drawSprite(data->window, data->background->sprite, NULL);
    if (data->tv->rect.left == 2880)
        sfRenderWindow_drawSprite(data->window, data->game_over->sprite, NULL);
    else {
        sfRenderWindow_drawSprite(data->window, data->duck->sprite, NULL);
        sfRenderWindow_drawSprite(data->window, data->dog->sprite, NULL);
    }
    sfRenderWindow_drawSprite(data->window, data->tv->sprite, NULL);
    sfRenderWindow_drawText(data->window, data->score->txt, NULL);
    move_cursor(data);
    check_duck_pos(data->duck);
    move_all(data);
}

void anim_all(data_t *data)
{
    data->duck->rect.left += 110;
    if (data->duck->rect.left == 330)
        data->duck->rect.left = 0;
    sfSprite_setTextureRect(data->duck->sprite, data->duck->rect);
    data->dog->rect.left += 110;
    if (data->dog->rect.left == 330)
        data->dog->rect.left = 0;
    sfSprite_setTextureRect(data->dog->sprite, data->dog->rect);
    data->menu->rect.left += 960;
    if (data->menu->rect.left == 3840)
        data->menu->rect.left = 0;
    sfSprite_setTextureRect(data->menu->sprite, data->menu->rect);
    data->game_over->rect.left += 960;
    if (data->game_over->rect.left == 3840)
        data->game_over->rect.left = 0;
    sfSprite_setTextureRect(data->game_over->sprite, data->game_over->rect);
}