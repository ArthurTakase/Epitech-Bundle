/*
** EPITECH PROJECT, 2021
** MY_TOOLS_H
** File description:
** my_tools
*/


#ifndef MY_TOOLS_H
#define MY_TOOLS_H

#include "my_struct.h"

/* Tools */

int check_no_solution_before(maze_t *dante);
int check_no_solution_after(maze_t *dante);
void free_maze(maze_t *dante);
int maze_height(const char *maze_1d);
int maze_width(const char *maze_1d);

/* Display Tools */

void display_result(maze_t *dante);
void print_help(void);
void *print_error(short help, void *return_value, const char *str);
int print_int_error(short help, const char *str);

#endif /* MY_TOOLS_H */
