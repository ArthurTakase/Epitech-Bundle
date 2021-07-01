/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen-master
** File description:
** tab
*/

#include "struct.h"

// Création d'un tableau pour un joueur
char **create_tab(void)
{
    char **tab = malloc(sizeof(char *) * 8);

    for (int i = 0; i < 8; i++)
        tab[i] = malloc(sizeof(char) * 8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            tab[i][j] = '.';
        }
    }
    return tab;
}

// Donne une couleur à la case en fonction de ce qu'elle contient
void color_tab(char tab_cell, int j)
{
    char sym[4] = {'2', '3', '4', '5'};

    my_printf("%c", tab_cell);
    if (j == 7)
        my_printf("\n");
    else
        my_printf(" ");
}

// Affiche le tableau donné en parametre
void show_tab(char **tab)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++)
            color_tab(tab[i][j], j);
    }

}

// Affiche les tableaux des 2 joueurs
void show_all(void)
{
    my_printf("\nmy positions:\n");
    show_tab(global->tab);
    my_printf("\nenemy's positions:\n");
    show_tab(global->tab_ad);
}

//Edit le tableau du joueur avec les nouvelles valeurs
void edit_tab(void)
{
    char arr_nbr[4] = {'2', '3', '4', '5'};
    int letter = global->coord[0] - 'A';
    int number = global->coord[1] - '0' - 1;

    if (number == -1)
        number = 1;
    if (my_in(global->tab[number][letter], arr_nbr)) {
        usleep(100);
        kill(global->pid_ad, SIGUSR1);
        my_printf("hit\n");
        global->tab[number][letter] = 'x';
    } else {
        usleep(100);
        kill(global->pid_ad, SIGUSR2);
        my_printf("missed\n");
        if (global->tab[number][letter] == '.')
            global->tab[number][letter] = 'o';
    }
}