/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** help
*/

#include "lib.h"

int help(void)
{
    my_putstr("\033[0;34mUSAGE\033[0m\n\
./my_defender [-h]\n\n\
\33[0;34mDESCRIPTION\033[0m\n\
Tuer des voitures avec des tours du moyen-age, quoi de plus normal ?\n\n\
\033[0;34mCONTROLS\033[0m\n\
Echap -> Pause\n\
Clic gauche -> Interactions\n");
    return 0;
}