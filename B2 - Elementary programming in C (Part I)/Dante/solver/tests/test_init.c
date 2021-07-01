/*
** EPITECH PROJECT, 2021
** Test Init
** File description:
** test_init
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdlib.h>
#include "my_init.h"
#include "my_struct.h"

Test(init, valid)
{

    char *maze_1d = malloc(sizeof(char) * 12);
    maze_t dante;

    maze_1d[0] = '*';
    maze_1d[1] = '*';
    maze_1d[2] = '*';
    maze_1d[3] = '\n';
    maze_1d[4] = 'X';
    maze_1d[5] = 'X';
    maze_1d[6] = '*';
    maze_1d[7] = '\n';
    maze_1d[8] = '*';
    maze_1d[9] = '*';
    maze_1d[10] = '*';
    maze_1d[11] = '\0';
    cr_assert(!str_to_array(maze_1d, &dante));
}

Test(init_solution, valid)
{
    maze_t dante;

    dante.maze = malloc(sizeof(char *) * 4);
    for (short i = 0; i < 3; ++i)
        dante.maze[i] = malloc(sizeof(char) * 4);
    dante.maze[0][0] = '*';
    dante.maze[0][1] = '*';
    dante.maze[0][2] = 'X';
    dante.maze[0][3] = '\0';
    dante.maze[1][0] = '*';
    dante.maze[1][1] = 'X';
    dante.maze[1][2] = '*';
    dante.maze[1][3] = '\0';
    dante.maze[2][0] = 'X';
    dante.maze[2][1] = '*';
    dante.maze[2][2] = 'X';
    dante.maze[2][3] = '\0';
    dante.maze[3] = NULL;
    dante.height = 3;
    dante.width = 3;
    cr_assert(!arrdup(&dante));
}
