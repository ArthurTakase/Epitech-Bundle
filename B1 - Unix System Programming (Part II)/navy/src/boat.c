/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen-master
** File description:
** boat
*/

#include "struct.h"

// Ajout du symbole dans la case correspondante
void append_tab(char x, char y, char sym)
{
    int x_pos = x - 65;
    int y_pos = y - 49;

    global->tab[y_pos][x_pos] = sym;
}

// Detection des cases où se trouvent les bateaux
void sub_place(int index, char *place)
{
    char symbole = place[index - 2];
    char l1 = place[index];
    char n1 = place[index + 1];
    char l2 = place[index + 3];
    char n2 = place[index + 4];

    if (l1 == l2)
        while (n1 != n2 + 1) {
            append_tab(l1, n1, symbole);
            n1++;
        }
    else
        while (l1 != l2 + 1) {
            append_tab(l1, n1, symbole);
            l1++;
        }
}

// Définition des zones à remplacer par des bateaux
void set_boat(char *place)
{
    sub_place(2, place);
    sub_place(10, place);
    sub_place(18, place);
    sub_place(26, place);
}