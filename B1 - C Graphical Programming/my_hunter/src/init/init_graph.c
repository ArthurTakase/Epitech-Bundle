/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** graph
*/

#include "../../include/csfml.h"
#include "../../include/my.h"

void init_background(data_t *data)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 960, 540};
    sfVector2f pos = {0, 0};
    sfVector2f move = {0, 0};

    sprite->texture = sfTexture_createFromFile("asset/img/back.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->background = sprite;
}

void init_tv(data_t *data)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 960, 540};
    sfVector2f pos = {0, 0};
    sfVector2f move = {0, 0};

    sprite->texture = sfTexture_createFromFile("asset/img/tv_full.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->tv = sprite;
}

int set_move_x(void)
{
    int side = rand() % 2;
    if (side == 1)
        return side;
    else
        return -1;
}

void init_duck(data_t *data, int move_x)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 110, 110};
    sfVector2f pos = {(rand() % 580) + 30, (rand() % 300) + 30};
    int side = set_move_x();
    sfVector2f move = {move_x * side, (rand() % 5) - 5/2};

    sprite->texture = sfTexture_createFromFile("asset/img/bird_full.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    if (side < 0)
        sprite->rect.top = 110;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->duck = sprite;
}

void init_cursor(data_t *data)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 512, 512};
    sfVector2f pos = {0, 0};
    sfVector2f move = {0, 0};
    sfVector2f scale = {0.1, 0.1};

    sprite->texture = sfTexture_createFromFile("asset/img/cursor.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    sfSprite_setScale(sprite->sprite, scale);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->cursor = sprite;
}