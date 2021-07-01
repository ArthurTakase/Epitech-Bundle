/*
** EPITECH PROJECT, 2021
** Tools
** File description:
** tools
*/

#include <stdlib.h>
#include "my_struct.h"
#include "my_maccro.h"

int check_no_solution_before(maze_t *dante)
{
    if (dante->maze[0][0] != '*' ||
    dante->maze[dante->height - 1][dante->width - 1] != '*') {
        return (EPITECH_ERROR);
    }
    return (MY_EXIT_SUCCESS);
}

int check_no_solution_after(maze_t *dante)
{
    if (dante->solution[dante->height - 1][dante->width - 1] == 0) {
        return (EPITECH_ERROR);
    }
    return (MY_EXIT_SUCCESS);
}

void free_maze(maze_t *dante)
{
    for (int i = 0; dante->maze[i]; ++i) {
        free(dante->solution[i]);
        free(dante->maze[i]);
    }
    free(dante->maze);
    free(dante->solution);
}

int maze_height(const char *maze_1d)
{
    int count = 0;

    for (int i = 0; maze_1d[i]; ++i) {
        if (maze_1d[i] == '\n') {
            ++count;
        }
    }
    return (++count);
}

int maze_width(const char *maze_1d)
{
    int i = 1;

    while (maze_1d[i] != '\n' && maze_1d[i] != '\0') {
        ++i;
    }
    return (i);
}
