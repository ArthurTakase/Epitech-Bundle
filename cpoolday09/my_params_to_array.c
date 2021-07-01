/*
** EPITECH PROJECT, 2020
** my_params_to_array
** File description:
** my_params_to_array
*/

#include "include/my.h"
#include <stdlib.h>

struct info_param fill(char *arg)
{
    struct info_param index_param;

    index_param.length = my_strlen(arg);
    index_param.str = arg;
    index_param.copy = my_strdup(arg);
    index_param.word_array = my_str_to_word_array(arg);
    return index_param;
}

struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    int z = ac + 1;
    struct info_param *info_param = malloc(sizeof(struct info_param) * z);

    while (i != ac) {
        info_param[i] = fill(av[i]);
        i++;
    }
    info_param[i].length = -1;
    info_param[i].str = 0;
    info_param[i].copy = 0;
    info_param[i].word_array = 0;
    return info_param;
}
