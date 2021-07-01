/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_jauge
*/

#include "struct.h"

sprite_t *init_jauge_part(run_t *run, sfIntRect rect, char *filepath)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sfSprite_setScale(sprite->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(sprite->sprite, (sfVector2f){256, 490});
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

void init_jauge(run_t *run)
{
    sfIntRect boder = {0, 0, 1024, 36};
    sfIntRect full = {0, 0, 0, 36};

    run->jauge = malloc(sizeof(jauge_t));
    run->jauge->border = init_jauge_part(run, boder, "asset/img/border.png");
    run->jauge->full = init_jauge_part(run, full, "asset/img/jauge.png");
}