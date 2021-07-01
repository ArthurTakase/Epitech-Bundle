/*
** EPITECH PROJECT, 2021
** Display Tools
** File description:
** display tools
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my_maccro.h"
#include "my_struct.h"

void display_result(maze_t *dante)
{
    int i = 0;

    while (dante->maze[i]) {
        printf("%s", dante->maze[i]);
        ++i;
        if (dante->maze[i]) {
            printf("\n");
        }
    }
}

void print_help(void)
{
    char *help_str = "\nYou could try ./solver -h\n";

    write(STDERR, help_str, strlen(help_str));
}

void *print_error(void *return_value, short help, const char *str)
{
    write(STDERR, str, strlen(str));
    if (help) {
        print_help();
    }
    return (return_value);
}

int print_int_error(short help, const char *str)
{
    write(STDERR, str, strlen(str));
    if (help) {
        print_help();
    }
    return (EPITECH_ERROR);
}
