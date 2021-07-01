/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen
** File description:
** left
*/

#include "struct.h"

int check_x(int i, int j, int player)
{
    if (player == 1) {
        if (global->tab[i][j] == 'x')
            return 1;
    } else {
        if (global->tab_ad[i][j] == 'x')
            return 1;
    }
    return 0;
}

// Regarde le nombre de bateau restant de chaque joueur
int left(int player)
{
    int left_x = 14;

    for (int i = 0; i < 8; i++)
        for (int  j = 0; j < 8; j++)
            left_x -= check_x(i, j, player);
    return left_x;
}

// Donne le nom du vainqueur
void win(void)
{
    if (left(1) == 0)
        my_printf("\nEnemy won\n");
    if (left(2) == 0)
        my_printf("\nI won\n");
}