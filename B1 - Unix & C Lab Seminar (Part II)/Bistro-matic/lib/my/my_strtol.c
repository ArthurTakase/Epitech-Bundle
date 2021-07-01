/*
** EPITECH PROJECT, 2020
** my_strtol
** File description:
** convert the initial part of the string given as parameter into
** an integer. The function will return the integer previously converted.
*/

#include <stdlib.h>

int my_compute_power_rec(int nb, int p);

int get_null(char *str)
{
    int i = 0;

    while (str[i] == ' ' && str[i])
        i++;
    if ((str[i] >= '0' && str[i] <= '9') && str[i])
        return i;
    return 0;
}

int my_int_nbr(char *str, int letter, int size, char **endptr)
{
    int number = 0;

    size--;
    for (size; size >= 0; size--) {
        number += ((str[letter] - '0') * my_compute_power_rec(10, size));
        letter++;
    }
    *endptr = &str[letter];
    return number;
}

int my_strtol(char *str, char **temp)
{
    int number = 0;
    int size = 0;
    int letter = get_null(str);

    if (letter == 0 && str[letter] == '\0') {
        *temp = &str[letter];
        return 0;
    }
    while ((str[letter] >= '0' && str[letter] <= '9') && str[letter] != '\0') {
        letter++;
        size++;
    }
    letter -= size;
    number = my_int_nbr(str, letter, size, temp);
    return number;
}
