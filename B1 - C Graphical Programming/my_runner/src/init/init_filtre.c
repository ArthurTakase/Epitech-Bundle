/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_filtre
*/

#include "struct.h"

void init_filtre(run_t *run)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, 1024, 512};

    sprite->texture = sfTexture_createFromFile("asset/img/scanline.jpg", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setColor(sprite->sprite, (sfColor){255, 255, 255, 20});
    run->filtre = sprite;
}

void init_ui(run_t *run)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/sprites.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = (sfIntRect){274, 255, 21, 16};
    sprite->pos = (sfVector2f){10, 10};
    sprite->value = 2;
    sfSprite_setScale(sprite->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    run->life = sprite;
}

sprite_t *init_void(int pos_x)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/sprites.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = (sfIntRect){252, 210, 20, 20};
    sprite->move = (sfVector2f){FIVE_SPD, 0};
    sprite->pos = (sfVector2f){pos_x, 420};
    sprite->value = -1;
    sprite->is_jump = 0;
    sfSprite_setScale(sprite->sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}