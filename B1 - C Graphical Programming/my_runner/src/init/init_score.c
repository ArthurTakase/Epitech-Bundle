/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** init_score
*/

#include "struct.h"

void init_score(run_t *run)
{
    score_t *score = malloc(sizeof(score_t));

    score->txt = sfText_create();
    score->font = sfFont_createFromFile("asset/font/score_font.ttf");
    score->pos = (sfVector2f){DIM_X / 2 - 1, 10};
    sfText_setPosition(score->txt, score->pos);
    sfText_setFont(score->txt, score->font);
    sfText_setCharacterSize(score->txt, 20);
    sfText_setColor(score->txt, sfWhite);
    sfText_setString(score->txt, "0");
    score->score = 0;
    run->score = score;
}

void init_best(run_t *run)
{
    score_t *score = malloc(sizeof(score_t));

    score->txt = sfText_create();
    score->font = sfFont_createFromFile("asset/font/score_font.ttf");
    score->pos = (sfVector2f){120, 60};
    sfText_setPosition(score->txt, score->pos);
    sfText_setFont(score->txt, score->font);
    sfText_setCharacterSize(score->txt, 20);
    sfText_setColor(score->txt, sfWhite);
    score->score = 0;
    run->best = score;
}