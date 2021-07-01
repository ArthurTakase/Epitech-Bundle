/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** only contain letter
*/

#include <stdlib.h>
#include "lib.h"

int my_str_isnum(char const *str)
{
    int len;

    len = my_strlen(str);
    for (int j = 0; j != len; j++ ) {
        if (str[j] < 48  || str[j] > 57)
            return 0;
    }
    return 1;
}