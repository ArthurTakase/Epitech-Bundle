/*
** EPITECH PROJECT, 2020
** My_Hunter
** File description:
** duck_bound
*/

#include "../include/csfml.h"
#include "../include/my.h"

void init_duck(data_t *data, int move_x);

void check_bird_colider(data_t *data)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    sfVector2f duck_pos = sfSprite_getPosition(data->duck->sprite);

    if (mouse_pos.x < duck_pos.x + 110 && mouse_pos.y < duck_pos.y + 100 &&
        mouse_pos.x > duck_pos.x && mouse_pos.y > duck_pos.y
        && data->tv->rect.left != 2880) {
        init_duck(data, 10 + (data->score->scr / 10));
        data->score->scr += 1;
        sfText_setString(data->score->txt, my_itos(data->score->scr, 10));
        sfSound_play(data->sound->duck_hit->sound);
        sfRenderWindow_drawSprite(data->window, data->white->sprite, NULL);
    } else if (data->tv->rect.left != 2880) {
        data->tv->rect.left += 960;
        sfSprite_setTextureRect(data->tv->sprite, data->tv->rect);
    }
    if (data->tv->rect.left != 2880)
        sfSound_play(data->sound->shot->sound);
    if (data->tv->rect.left == 2880)
        sfSound_play(data->sound->dog_hit->sound);
}

void duck_set_pos(sprite_t *duck, int side)
{
    if (side == 1) {
        duck->move.y = (rand() % 15) - 15/2;
        duck->pos.x = 690;
        duck->rect.top = 110;
    } else {
        duck->move.y = (rand() % 15) * -1;
        duck->pos.x = 0;
        duck->rect.top = 0;
    }
    duck->move.x *= -1.02;
    sfSprite_setTextureRect(duck->sprite, duck->rect);
}

void check_duck_pos(sprite_t *duck)
{
    if (sfSprite_getPosition(duck->sprite).x + duck->move.x >= 620)
        duck_set_pos(duck, 1);
    if (sfSprite_getPosition(duck->sprite).x + duck->move.x <= 20)
        duck_set_pos(duck, 0);
    if (sfSprite_getPosition(duck->sprite).y + duck->move.y <= 30) {
        duck->move.y = rand() % 15 + 2;
        duck->pos.y = 0;
    }
    if (sfSprite_getPosition(duck->sprite).y + duck->move.y > 350) {
        duck->move.y = (rand() % 15) - 15/2 - 2;
        duck->pos.y = 490;
    }
}