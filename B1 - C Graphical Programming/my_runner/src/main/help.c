/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** help
*/

#include "struct.h"

int help(void)
{
    my_putstr("\033[0;34mUSAGE\033[0m\n");
    my_putstr("./my_runner [map]\n\n");
    my_putstr("\33[0;34mDESCRIPTION\033[0m\n");
    my_putstr("map: fichier contenant une map pour le jeu\n\n");
    my_putstr("\033[0;34mGOAL\033[0m\n");
    my_putstr("Courir jusqu'au drapeau sans se faire toucher");
    my_putstr("par les ennemis.\n\n");
    my_putstr("\033[0;34mCONTROLS\033[0m\n");
    my_putstr("Clic gauche: sauter\n");
    my_putstr("Echap: pause\n");
    return 0;
}