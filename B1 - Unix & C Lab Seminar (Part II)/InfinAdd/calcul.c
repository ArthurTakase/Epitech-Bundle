/*
** EPITECH PROJECT, 2020
** calcul.c
** File description:
** calcul
*/

#include "include/my.h"
#include "include/infinit.h"
#include <stdlib.h>

// Additionne les chiffres un par un et met le resultat dans un array
char *add_all(char **argv)
{
    int temp = 0;
    int result_temp;
    int i = my_strlen(argv[1]) - 1;
    char *result = malloc(sizeof(char) * (my_strlen(argv[1]) + 1));

    for (i; i >= 0; i--) {
        result_temp = ((int)argv[1][i] - 48) + ((int)argv[2][i] - 48) + temp;
        if (result_temp > 9) {
            temp = 1;
            result[i] = (result_temp % 10) + 48;
        } else {
            result[i] = result_temp + 48;
            temp = 0;
        }
    }
    if (temp == 1)
        my_putchar('1');
    return result;
}

// Soustrait les chiffres un par un et met le resultat dans un array
char *minus_all(char *argv_minus, char *argv_max)
{
    int temp;
    int result_temp;
    char *result = malloc(sizeof(char) * (my_strlen(argv_minus) + 1));
    int max;

    for (int i = my_strlen(argv_minus) - 1; i >= 0; i--) {
        if (argv_minus[i] > argv_max[i]) {
            max = (argv_max[i] - 48) + 10;
            result_temp = max - (argv_minus[i] - 48 + temp);
            temp = 1;
        } else {
            max = argv_max[i] - 48;
            result_temp = max - (argv_minus[i] - 48 + temp);
            temp = 0;
        }
        result[i] = result_temp + 48;
    }
    return result;
}
