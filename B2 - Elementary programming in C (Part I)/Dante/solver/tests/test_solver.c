/*
** EPITECH PROJECT, 2021
** Test Solver
** File description:
** test_solver
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_redirect.h"
#include "my_errors.h"
#include "solver.h"

Test(solver, valid, .init = redirect_all_std)
{
    char *av[2] = {"./solver", "mazes/10x10_maze"};
    char *maze_1d = error_handling(2, (const char **)av);

    solver(maze_1d);
    cr_assert(1);
}
