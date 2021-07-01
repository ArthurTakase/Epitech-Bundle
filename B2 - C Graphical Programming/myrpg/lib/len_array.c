/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-arthur.decaen
** File description:
** len_array
*/

int len_array(char **array)
{
    int i = 0;

    while (*array) {
        i++;
        array++;
    }
    return i;
}