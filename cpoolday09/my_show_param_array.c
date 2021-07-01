/*
** EPITECH PROJECT, 2020
** my_show_param_array.c
** File description:
** my_show_param_array.c
*/

#include "include/my.h"

int my_show_param_array(struct info_param const *par)
{
    for (int i = 0; par[i].copy != 0; i++){
        my_putstr(par[i].str);
        my_putchar('\n');
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
    }
    return 0;
}
