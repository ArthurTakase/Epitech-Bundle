/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** txt_from_value
*/

#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

void set_txt(txt_t *txt, int new_value)
{
    char *new_txt = "0";

    if (new_value != 0)
        new_txt = my_itos(new_value, 10);
    sfText_setString(txt->txt, new_txt);
    if (new_value != 0)
        free(new_txt);
}