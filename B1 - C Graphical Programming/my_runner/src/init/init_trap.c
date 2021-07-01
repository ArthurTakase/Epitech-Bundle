/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** init_trap
*/

#include "struct.h"

// Piège au sol
sprite_t *init_trap_1(int pos_x)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/trap.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = (sfIntRect){0, 0, 25, 8};
    sprite->move = (sfVector2f){FIVE_SPD, 0};
    sprite->pos = (sfVector2f){pos_x, 465};
    sprite->value = 0;
    sprite->is_jump = 0;
    sfSprite_setScale(sprite->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

// Slime
sprite_t *init_trap_2(int pos_x)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/sprites.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = (sfIntRect){401, 198, 21, 13};
    sprite->move = (sfVector2f){SIX_SPD - 2, 0};
    sprite->pos = (sfVector2f){pos_x, 449};
    sprite->value = 1;
    sprite->is_jump = 0;
    sfSprite_setScale(sprite->sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

// truc qui vole
sprite_t *init_trap_3(int pos_x)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/sprites.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = (sfIntRect){441, 297, 20, 14};
    sprite->move = (sfVector2f){SIX_SPD, 0};
    sprite->pos = (sfVector2f){pos_x, 365};
    sprite->value = 2;
    sprite->is_jump = 0;
    sfSprite_setScale(sprite->sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

// drapeau de fin
sprite_t *init_flag(int pos_x)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/sprites.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = (sfIntRect){252, 210, 20, 20};
    sprite->move = (sfVector2f){FIVE_SPD, 0};
    sprite->pos = (sfVector2f){pos_x, 420};
    sprite->value = 3;
    sprite->is_jump = 0;
    sfSprite_setScale(sprite->sprite, (sfVector2f){3, 3});
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

// Pièce
sprite_t *init_trap_coin(int pos_x)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile("asset/img/coin.png", NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = (sfIntRect){0, 0, 32, 32};
    sprite->move = (sfVector2f){FIVE_SPD, 0};
    sprite->pos = (sfVector2f){pos_x, rand() % (400 + 1 - 365) + 365};
    sprite->value = 4;
    sprite->is_jump = 0;
    sfSprite_setScale(sprite->sprite, (sfVector2f){1, 1});
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}
