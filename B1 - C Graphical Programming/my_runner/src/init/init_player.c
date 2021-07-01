/*
** EPITECH PROJECT, 2020
** paralax
** File description:
** init_player
*/

#include "struct.h"

void init_char(run_t *run)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 14, 18};
    sfVector2f pos = {250, 428};
    sfVector2f scale = {3, 3};

    sprite->texture = sfTexture_createFromFile("asset/img/perso.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->is_jump = 0;
    sprite->jump_height = 0;
    sprite->value = 1;
    sfSprite_setScale(sprite->sprite, scale);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    run->player = sprite;
}

void init_cursor(run_t *run)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 27, 28};
    sfVector2f pos = {0, 0};

    sprite->texture = sfTexture_createFromFile("asset/img/cursor.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    run->cursor = sprite;
}