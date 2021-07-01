/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** set_value
*/

void my_sort_int_array(int *array, int size);

// Look at the 3 cells around it, take the lowest value and add 1 to it.
// Returns the result of this operation
int min_int(int **dup, int x, int y)
{
    int int_value[3] = {dup[y - 1][x], dup[y][x - 1], dup[y - 1][x - 1]};

    my_sort_int_array(int_value, 3);
    return int_value[0] + 1;
}

// Look at each cell from the (1;1) box and run the min_int function
int **set_dup(int **dup, int height, int width)
{
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width; x++) {
            if (dup[y][x] == -1)
                dup[y][x] = min_int(dup, x, y);
        }
    }
    return dup;
}