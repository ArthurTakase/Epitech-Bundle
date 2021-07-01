/*
** EPITECH PROJECT, 2021
** Solver
** File description:
** solver
*/

#include "my_struct.h"
#include "my_maccro.h"
#include "my_init.h"
#include "solver.h"

int solver(char *maze_1d)
{
    maze_t dante;

    if (str_to_array(maze_1d, &dante) || arrdup(&dante)) {
        return (EPITECH_ERROR);
    }
    solve_maze(&dante);
    return (MY_EXIT_SUCCESS);
}
