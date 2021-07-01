/*
** EPITECH PROJECT, 2020
** final stumper
** File description:
** tool
*/

int get_corner(char *get)
{
    if (get[0] == 'o' && get[1] == 'o' && get[2] == 'o' && get[3] == 'o')
        return 1;
    if (get[0] == '/' && get[1] == '\\' && get[2] == '/' && get[3] == '\\')
        return 2;
    if (get[0] == 'A' && get[1] == 'A' && get[2] == 'C' && get[3] == 'C')
        return 3;
    if (get[0] == 'A' && get[1] == 'C' && get[2] == 'C' && get[3] == 'A')
        return 4;
    if (get[0] == 'A' && get[1] == 'C' && get[2] == 'A' && get[3] == 'C')
        return 5;
    return 10;
}
