/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** init_txt
*/

#include "defender.h"
#include <stdlib.h>

txt_t *init_txt(sfVector2f pos, char *txt, int size, int value)
{
    txt_t *text = malloc(sizeof(txt_t));

    text->txt = sfText_create();
    text->font = sfFont_createFromFile("asset/font/1.ttf");
    text->pos = (sfVector2f)pos;
    text->value = value;
    text->txt_char = txt;
    sfText_setPosition(text->txt, text->pos);
    sfText_setFont(text->txt, text->font);
    sfText_setCharacterSize(text->txt, size);
    sfText_setColor(text->txt, sfWhite);
    sfText_setString(text->txt, text->txt_char);
    return text;
}