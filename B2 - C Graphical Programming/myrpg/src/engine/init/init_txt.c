/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_txt
*/

#include "rpg.h"
#include <stdlib.h>

txt_t *new_txt(sfVector2f pos, char *txt, int size, int value)
{
    txt_t *text = malloc(sizeof(txt_t));

    text->txt = sfText_create();
    text->font = sfFont_createFromFile("asset/font/1.ttf");
    text->pos = (sfVector2f)pos;
    text->value = value;
    sfText_setPosition(text->txt, text->pos);
    sfText_setFont(text->txt, text->font);
    sfText_setCharacterSize(text->txt, size);
    sfText_setColor(text->txt, sfWhite);
    sfText_setString(text->txt, txt);
    return text;
}

all_txt_t *init_txt(void)
{
    all_txt_t *txt = malloc((sizeof(all_txt_t)));

    txt->fight_turn = new_txt((sfVector2f){0, 0}, "PLAYER's turn", 30, 0);
    sfText_setColor(txt->fight_turn->txt, (sfColor){255, 255, 255, 35});
    txt->fight_result = new_txt((sfVector2f){400, 150}, "", 30, 0);
    txt->fight_gains = new_txt((sfVector2f){435, 200}, "", 18, 0);
    txt->potion = new_txt((sfVector2f){330, 165}, "0", 18, 0);
    txt->key = new_txt((sfVector2f){330, 225}, "0", 18, 0);
    txt->lvl = new_txt((sfVector2f){500, 165}, "0", 18, 0);
    txt->life = new_txt((sfVector2f){500, 213}, "0", 18, 0);
    txt->slash = new_txt((sfVector2f){550, 213}, "/", 18, 0);
    txt->max_life = new_txt((sfVector2f){600, 213}, "0", 18, 0);
    txt->att = new_txt((sfVector2f){500, 260}, "0", 18, 0);
    txt->gold = new_txt((sfVector2f){527, 352}, "0", 18, 0);
    return txt;
}