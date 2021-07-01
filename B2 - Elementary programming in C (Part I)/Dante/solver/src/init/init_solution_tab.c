/*
** EPITECH PROJECT, 2021
** Init Solution Tab
** File description:
** init_solution_tab
*/

#include <stdlib.h>
#include "my_tools.h"
#include "my_maccro.h"
#include "my_struct.h"

static void deep_comparaison(maze_t *dante, int i)
{
    for (int j = 0; dante->maze[i][j]; ++j) {
        if (dante->maze[i][j] == 'X') {
            dante->solution[i][j] = -1;
        } else if (dante->maze[i][j] == '*') {
            dante->solution[i][j] = 0;
        }
    }
}

static void convert_content(maze_t *dante)
{
    for (int i = 0; dante->maze[i]; ++i) {
        deep_comparaison(dante, i);
    }
}

static void fill_int_tab(int *maze, short nb, int len)
{
    for (int i = 0; i < len; ++i) {
        maze[i] = nb;
    }
}

static int init_solution(maze_t *dante)
{
    dante->solution = malloc(sizeof(int *) * (dante->height + 1));

    if (!dante->solution) {
        return (print_int_error(0, "ERROR: Malloc failed.\n"));
    }
    for (int i = 0; i < dante->height; ++i) {
        dante->solution[i] = malloc(sizeof(int) * (dante->width + 1));
        if (!dante->solution[i]) {
            return (print_int_error(0, "ERROR: Malloc failed.\n"));
        }
        fill_int_tab(dante->solution[i], -2, dante->width + 1);
    }
    dante->solution[dante->height] = NULL;
    return (MY_EXIT_SUCCESS);
}

int arrdup(maze_t *dante)
{
    if (init_solution(dante)) {
        for (int i = 0; dante->maze[i]; ++i)
            free(dante->maze[i]);
        free(dante->maze);
        return (EPITECH_ERROR);
    }
    convert_content(dante);
    return (MY_EXIT_SUCCESS);
}
