/*
** EPITECH PROJECT, 2021
** Solve Maze
** File description:
** solve_maze
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_struct.h"
#include "my_maccro.h"
#include "my_tools.h"
#include "solver.h"

static void expand_solution(maze_t *dante, int nb, int i, int j)
{
    if (dante->maze[i][j + 1] && dante->solution[i][j + 1] == 0) {
        dante->solution[i][j + 1] = nb + 1;
    }
    if (dante->maze[i + 1] && dante->solution[i + 1][j] == 0) {
        dante->solution[i + 1][j] = nb + 1;
    }
    if (j - 1 >= 0 && dante->solution[i][j - 1] == 0) {
        dante->solution[i][j - 1] = nb + 1;
    }
    if (i - 1 >= 0 && dante->solution[i - 1][j] == 0) {
        dante->solution[i - 1][j] = nb + 1;
    }
}

static void solve_deep(maze_t *dante, int nb, int i)
{
    for (int j = 0; dante->maze[i][j]; ++j) {
        if (dante->solution[i][j] == nb) {
            expand_solution(dante, nb, i, j);
        }
    }
}

static void solve_it(maze_t *dante, int nb)
{
    for (int i = 0; dante->maze[i]; ++i) {
        solve_deep(dante, nb, i);
    }
}

static int is_finish(maze_t *dante)
{
    if (dante->solution[dante->height - 1][dante->width - 1] != 0) {
        return (EPITECH_ERROR);
    }
    return (MY_EXIT_SUCCESS);
}

void solve_maze(maze_t *dante)
{
    int nb = 1;

    if (check_no_solution_before(dante)) {
        printf("no solution found");
        return;
    }
    dante->solution[0][0] = nb;
    while (nb < dante->width * (dante->height / 2 + 1) && !is_finish(dante)) {
        solve_it(dante, nb);
        ++nb;
    }
    if (check_no_solution_after(dante)) {
        printf("no solution found");
        return;
    }
    apply_result(dante);
    display_result(dante);
    free_maze(dante);
}
