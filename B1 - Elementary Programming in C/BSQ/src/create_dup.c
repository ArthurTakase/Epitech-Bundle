/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** create_dup
*/

#include <stdlib.h>

// Look at the char of the first array in (x;y)
// and return the corresponding number
int check_char(char **map, int x, int y)
{
    if (x == 0 || y == 0)
        if (map[y][x] == '.')
            return 1;
    if (map[y][x] == 'o')
        return 0;
    return -1;
}

//Creation of a second array of the same size as the first one.
//Contains only 1 (. if x or y = 0), 0 (o) and -1.
int **create_dup(char **map, int nb_y, int nb_x)
{
    int **dup = malloc(sizeof(int *) * nb_y + 2);

    for (int i = 0; i < nb_y; i++)
        dup[i] = malloc(sizeof(int) * nb_x + 2);
    for (int y = 0; y < nb_y; y++) {
        for (int x = 0; x < nb_x; x++) {
            dup[y][x] = check_char(map, x, y);
        }
    }
    return dup;
}