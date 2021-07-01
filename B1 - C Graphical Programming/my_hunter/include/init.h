/*
** EPITECH PROJECT, 2020
** My_Hunter
** File description:
** init
*/

#include "csfml.h"

#define HELP_STRING "\033[1;34mUSAGE\033[0m\n\
./my_hunter [-h]\n\n\
\033[1;34mDESCRIPTION\033[0m\n\
-h: Displays game support\n\n\
\033[1;34mGOAL\033[0m\n\
Great hunter that you are, you must kill as many ducks as possible.\n\
Your time is unlimited, but beware, you only have the right to make\
three mistakes (symbolized by the ammunition on the right of the screen).\n\
Don't shoot the dog, it's your friend...\n\n\
\033[1;34mCOMMANDS\033[0m\n\
Left-click to shot.\n"

void init_duck(data_t *data, int move_x);
void init_tv(data_t *data);
void init_background(data_t *data);
void init_window(data_t *data);
void init_score(data_t *data);
void init_dog(data_t *data);
void game(data_t *data);
void init_cursor(data_t *data);
void init_flash(data_t *data);
void init_menu(data_t *data);
void init_sound(data_t *data);
