/*
** EPITECH PROJECT, 2021
** Init
** File description:
** init
*/

#include <string.h>
#include <stdlib.h>
#include "my_struct.h"
#include "my_maccro.h"
#include "my_tools.h"

static int init_arr(maze_t *dante)
{
    dante->maze = malloc(sizeof(char *) * (dante->height + 1));

    if (!dante->maze) {
        return (print_int_error(0, "ERROR: Malloc failed.\n"));
    }
    for (int i = 0; i < dante->height; ++i) {
        dante->maze[i] = malloc(sizeof(char) * (dante->width + 1));
        if (!dante->maze[i]) {
            return (print_int_error(0, "ERROR: Malloc failed.\n"));
        }
        memset(dante->maze[i], '\0', dante->width + 1);
        if (!dante->maze[i]) {
            return (print_int_error(0, "ERROR: Memset failed.\n"));
        }
    }
    dante->maze[dante->height] = NULL;
    return (MY_EXIT_SUCCESS);
}

static void content_to_arr(char *maze_1d, maze_t *dante)
{
    int j = 0;
    int k = 0;

    for (int i = 0; maze_1d[i]; ++i) {
        if (maze_1d[i] == '\n') {
            ++j;
            k = 0;
        } else {
            dante->maze[j][k] = maze_1d[i];
            ++k;
        }
    }
    free(maze_1d);
}

int str_to_array(char *maze_1d, maze_t *dante)
{
    dante->height = maze_height(maze_1d);
    dante->width = maze_width(maze_1d);
    if (init_arr(dante)) {
        free(maze_1d);
        return (EPITECH_ERROR);
    }
    content_to_arr(maze_1d, dante);
    return (MY_EXIT_SUCCESS);
}
