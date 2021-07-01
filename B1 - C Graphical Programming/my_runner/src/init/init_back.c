/*
** EPITECH PROJECT, 2020
** paralax
** File description:
** init
*/

#include "struct.h"

sprite_t *init_back(char const *file, int move_x, int pos_x, run_t *run)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));
    sfIntRect rect = {0, 0, DIM_X, DIM_Y};
    sfVector2f move = {move_x, 0};
    sfVector2f pos = {pos_x, 0};
    char *src = malloc(my_strlen(file) + my_strlen(run->option->level) + 1);

    my_strcat(my_strcpy(src, run->option->level), file);
    sprite->texture = sfTexture_createFromFile(src, NULL);
    sprite->sprite = sfSprite_create();
    sprite->rect = rect;
    sprite->move = move;
    sprite->pos = pos;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    return sprite;
}

void init_background(run_t *run)
{
    bg_t *bg = malloc(sizeof(bg_t));

    bg->bg1 = init_back("bg1.png", ONE_SPD, 0, run);
    bg->bg2 = init_back("bg2.png", TWO_SPD, 0, run);
    bg->bg3 = init_back("bg3.png", THREE_SPD, 0, run);
    bg->bg4 = init_back("bg4.png", FOUR_SPD, 0, run);
    bg->bg5 = init_back("bg5.png", FIVE_SPD, 0, run);
    bg->bg6 = init_back("bg6.png", SIX_SPD, 0, run);
    bg->bg1_b = init_back("bg1.png", ONE_SPD, DIM_X, run);
    bg->bg2_b = init_back("bg2.png", TWO_SPD, DIM_X, run);
    bg->bg3_b = init_back("bg3.png", THREE_SPD, DIM_X, run);
    bg->bg4_b = init_back("bg4.png", FOUR_SPD, DIM_X, run);
    bg->bg5_b = init_back("bg5.png", FIVE_SPD, DIM_X, run);
    bg->bg6_b = init_back("bg6.png", SIX_SPD, DIM_X, run);
    run->bg = bg;
}

void init_window(run_t *runner)
{
    sfVideoMode mode = {DIM_X, DIM_Y, 32};
    runner->window = sfRenderWindow_create(mode, "My_Hunter", 7, NULL);
    sfRenderWindow_setFramerateLimit(runner->window, runner->option->fps);
    sfRenderWindow_setMouseCursorVisible(runner->window, sfFalse);
}