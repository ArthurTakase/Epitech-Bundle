/*
** EPITECH PROJECT, 2021
** Apply Solution
** File description:
** apply_solution
*/

#include "my_struct.h"

static void check_last_two(maze_t *dante, int nb)
{
    if (dante->maze[dante->height][dante->width + 1] &&
    dante->solution[dante->height][dante->width + 1] == nb) {
        ++dante->width;
    } else if (dante->maze[dante->height + 1] &&
    dante->solution[dante->height + 1][dante->width] == nb) {
        ++dante->height;
    }
}

static void apply_path(maze_t *dante, int nb)
{
    if (dante->width - 1 >= 0 &&
    dante->solution[dante->height][dante->width - 1] == nb) {
        --dante->width;
    } else if (dante->height - 1 >= 0 &&
    dante->solution[dante->height - 1][dante->width] == nb) {
        --dante->height;
    } else {
        check_last_two(dante, nb);
    }
}

void apply_result(maze_t *dante)
{
    int nb = dante->solution[dante->height - 1][dante->width - 1] - 1;

    --dante->height;
    --dante->width;
    while (nb > 0) {
        dante->maze[dante->height][dante->width] = 'o';
        apply_path(dante, nb);
        --nb;
    }
    dante->maze[0][0] = 'o';
}
