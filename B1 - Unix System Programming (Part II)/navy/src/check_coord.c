/*
** EPITECH PROJECT, 2021
** navy
** File description:
** check_coord
*/

#include "struct.h"

int check_coord32(char *buffer)
{
    int(*funct[32])(char) = {number, dot, letter, number, dot, letter, number,
                            jump, number, dot, letter, number, dot, letter,
                            number, jump, number, dot, letter, number, dot,
                            letter, number, jump, number, dot, letter, number,
                            dot, letter, number, jump};

    for (int i = 0; i < my_strlen(buffer); i++)
        if ((*funct[i])(buffer[i]))
            return 1;
    return 0;
}

//Vérifie les coordonnées des bateaux
int check_coord31(char *buffer)
{
    int(*funct[31])(char) = {number, dot, letter, number, dot, letter, number,
                            jump, number, dot, letter, number, dot, letter,
                            number, jump, number, dot, letter, number, dot,
                            letter, number, jump, number, dot, letter, number,
                            dot, letter, number};

    for (int i = 0; i < my_strlen(buffer); i++)
        if ((*funct[i])(buffer[i]))
            return 1;
    return 0;
}