/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** set_x
*/

// Replace the '.' with 'X' in the final zone
char **set_x(char **map, int *value)
{
    for (int y = value[2]; y < value[2] + value[0]; y++) {
        for (int x = value[1]; x < value[1] + value[0]; x++) {
            map[y][x] = 'x';
        }
    }
    return map;
}

// Search for the highest value in the array with its coordinates
char **print_x(int **dup, char **map, int height, int width)
{
    int value[3] = {0, 0, 0};

    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width; x++) {
            if (dup[y][x] > value[0]) {
                value[0] = dup[y][x];
                value[1] = x - value[0] + 1;
                value[2] = y - value[0] + 1;
            }
        }
    }
    return set_x(map, value);
}