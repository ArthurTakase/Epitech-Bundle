/*
** EPITECH PROJECT, 2021
** navy
** File description:
** check_part
*/

#include "struct.h"

int number(char elem)
{
    char number_arr[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    if (!my_in(elem, number_arr))
        return 1;
    return 0;
}

int letter(char elem)
{
    char letter_arr[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    if (!my_in(elem, letter_arr))
        return 1;
    return 0;
}

int dot(char elem)
{
    if (elem != ':')
        return 1;
    return 0;
}

int jump(char elem)
{
    if (elem != '\n')
        return 1;
    return 0;
}