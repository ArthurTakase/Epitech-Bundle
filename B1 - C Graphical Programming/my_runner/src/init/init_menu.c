/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** init_menu
*/

#include "struct.h"

sprite_t *init_menu_img(char *filepath)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, DIM_X, DIM_Y};

    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sfSprite_setPosition(sprite->sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

menu_t *init_menu(run_t *run)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->defeat_1 = init_menu_img("asset/img/menu/defeat_1.png");
    menu->win_1 = init_menu_img("asset/img/menu/win_1.png");
    menu->cc_1 = init_menu_img("asset/img/menu/50cc.png");
    menu->cc_2 = init_menu_img("asset/img/menu/100cc.png");
    menu->level1 = init_menu_img("asset/img/menu/level1.png");
    menu->level2 = init_menu_img("asset/img/menu/level2.png");
    menu->level3 = init_menu_img("asset/img/menu/level3.png");
    menu->level4 = init_menu_img("asset/img/menu/level4.png");
    menu->pause = init_txt(run, (sfVector2f){100, 100}, "> PAUSE", 50);
    menu->current_bg = menu->level1->sprite;
    menu->current_fps = menu->cc_1->sprite;
    run->menu = menu;
}

score_t *init_txt(run_t *run, sfVector2f position, char *script, int size)
{
    score_t *text = malloc(sizeof(score_t));
    sfVector2f pos = position;
    sfColor color = sfWhite;

    text->txt = sfText_create();
    text->font = sfFont_createFromFile("asset/font/score_font.ttf");
    text->pos = pos;
    sfText_setPosition(text->txt, text->pos);
    sfText_setFont(text->txt, text->font);
    sfText_setCharacterSize(text->txt, size);
    sfText_setColor(text->txt, color);
    sfText_setString(text->txt, script);
    return text;
}