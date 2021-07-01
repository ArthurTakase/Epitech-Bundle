/*
** EPITECH PROJECT, 2020
** My_Hunter
** File description:
** init_misc
*/

#include "../../include/csfml.h"
#include "../../include/my.h"

void init_window(data_t *data)
{
    sfVideoMode mode = {960, 540, 32};
    data->window = sfRenderWindow_create(mode, "My_Hunter", 7, NULL);
    sfRenderWindow_setFramerateLimit(data->window, 30);
    sfRenderWindow_setMouseCursorVisible(data->window, sfFalse);
}

void init_score(data_t *data)
{
    score_t *score = malloc(sizeof(score_t));
    sfVector2f pos = {815, 430};
    sfColor color = sfBlack;

    score->txt = sfText_create();
    score->font = sfFont_createFromFile("asset/font/pastelfont.ttf");
    score->pos = pos;
    sfText_setPosition(score->txt, score->pos);
    sfText_setFont(score->txt, score->font);
    sfText_setCharacterSize(score->txt, 45);
    sfText_setColor(score->txt, color);
    sfText_setString(score->txt, "0");
    score->scr = 0;
    data->score = score;

}

void init_flash(data_t *data)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 960, 540};
    sfVector2f pos = {0, 0};
    sfVector2f move = {0, 0};

    sprite->texture = sfTexture_createFromFile("asset/img/white.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->white = sprite;
}

void init_menu(data_t *data)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 960, 540};
    sfVector2f pos = {0, 0};
    sfVector2f move = {0, 0};

    sprite->texture = sfTexture_createFromFile("asset/img/menu_full.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->pos = pos;
    sprite->move = move;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    data->menu = sprite;
}