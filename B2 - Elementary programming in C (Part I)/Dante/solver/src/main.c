/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-dante-arthur.decaen
** File description:
** main
*/

#include "my_maccro.h"
#include "my_errors.h"
#include "solver.h"

int main(int ac, const char **av)
{
    char *maze = error_handling(ac, av);

    if (!maze) {
        return (EPITECH_ERROR);
    }
    return (solver(maze));
}
