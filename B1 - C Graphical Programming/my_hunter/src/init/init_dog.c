/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** graph
*/

#include "../../include/csfml.h"
#include "../../include/my.h"

void init_game_over(data_t *data)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 960, 540};
    sfVector2f pos = {0, 0};
    sfVector2f move = {0, 0};

    sprite->texture = sfTexture_createFromFile("asset/img/over_full.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->game_over = sprite;
}

void init_dog_entity(data_t *data)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 110, 72};
    sfVector2f pos = {0, 430};
    sfVector2f move = {10, 0};
    sfVector2f scale = {1.2, 1.2};

    sprite->texture = sfTexture_createFromFile("asset/img/dog_full.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    sfSprite_setScale(sprite->sprite, scale);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->dog = sprite;
}

void init_dog(data_t *data)
{
    init_game_over(data);
    init_dog_entity(data);
}