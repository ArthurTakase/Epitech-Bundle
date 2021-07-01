/*
** EPITECH PROJECT, 2020
** choice.c
** File description:
** chose function fo the calcul
*/

#include <stdlib.h>
#include "include/my.h"

char *add_all(char **argv);

char *minus_all(char *argv_minus, char *argv_max);

// Determine si le nombre est negatif
int get_neg(char *argv)
{
    if (argv[0] == '-')
        return 1;
    return 0;
}

// Supprime le - d'un nombre negatif
char *set_neg(char *argv, int neg)
{
    char *new = malloc(sizeof(argv));
    if (neg == 0)
        return argv;
    for (int i = 1; i < my_strlen(argv); i++) {
        new[i - 1] = argv[i];
    }
    return new;
}

// Fonction qui determine quel nombre est le plus petit
// Retourne l'index du nombre le plus petit
// Retourne 0 si les nombres sont identiques
int minus(char *un, char *deux)
{
    if (my_strcmp(un, deux) > 0)
        return 1;
    if (my_strcmp(un, deux) < 0)
        return 2;
    return 0;
}

// Pour une soustraction, regarde si le nombre avec un - est le plus grand
// Si vrai, print un -
int print_minus(char **argv, int neg1, int neg2)
{
    int minus_get = minus(argv[1], argv[2]);

    if (minus_get == neg1 || (minus_get == 2 && neg2 == 1)) {
        if (my_strcmp(argv[1], argv[2]) != 0)
            my_putchar('-');
    }
    return 0;
}

// Determine quel calcul faire en fonction du nombre de chiffre negatif
char *choice_calc(char **argv, int neg1, int neg2)
{
    if (neg1 == 0 && neg2 == 0) {
        return add_all(argv);
    } else if (neg1 == 1 && neg2 == 1) {
        my_putchar('-');
        return add_all(argv);
    } else {
        print_minus(argv, neg1, neg2);
        if (minus(argv[1], argv[2]) == 0) {
            return minus_all(argv[1], argv[1]);
        } else if (minus(argv[1], argv[2]) == 1) {
            return minus_all(argv[2], argv[1]);
        } else {
            return minus_all(argv[1], argv[2]);
        }
    }
}
