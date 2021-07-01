/*
** EPITECH PROJECT, 2021
** Error Handling
** File description:
** error_handling
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "my_tools.h"
#include "my_maccro.h"
#include "my_usage.h"

static char *file_to_str(const char *filepath)
{
    struct stat file;
    off_t size;
    char *content;
    int fd = open(filepath, O_RDONLY);

    if (fd == MY_EXIT_ERROR) {
        return (NULL);
    }
    stat(filepath, &file);
    size = file.st_size;
    content = malloc(sizeof(char) * (size + END_OF_FILE));
    if (!content) {
        return (NULL);
    }
    if (!size || read(fd, content, size) == MY_EXIT_ERROR) {
        return (NULL);
    }
    content[size] = '\0';
    close(fd);
    return (content);
}

static int next_char_back_n(const char *maze_1d, int i, int width, int *len)
{
    if (maze_1d[i + 1] == '\n') {
        if (width != *len) {
            return (EPITECH_ERROR);
        }
        *len = 0;
    }
    return (MY_EXIT_SUCCESS);
}

static int is_a_rectangle(const char *maze_1d)
{
    int width = maze_width(maze_1d);
    int len = 0;

    for (int i = 0; maze_1d[i]; ++i) {
        if (maze_1d[i] != '\n') {
            ++len;
        }
        if (next_char_back_n(maze_1d, i, width, &len)) {
            return (EPITECH_ERROR);
        }
    }
    len = 0;
    for (int i = strlen(maze_1d) - 1; maze_1d[i] != '\n' && i >= 0; --i) {
        ++len;
    }
    if (width != len) {
        return (EPITECH_ERROR);
    }
    return (MY_EXIT_SUCCESS);
}

static int valid_maze(const char *maze_1d)
{
    if (!maze_1d) {
        return (print_int_error(1, "ERROR: Incorrect file.\n"));
    }
    if (is_a_rectangle(maze_1d)) {
        return (print_int_error(1, "ERROR: The maze isn't a rectangle \
(neigher a square)\n"));
    }
    for (int i = 0; maze_1d[i]; ++i) {
        if (maze_1d[i] != 'X' && maze_1d[i] != '*' && maze_1d[i] != '\n') {
            return (print_int_error(1, "ERROR: Invalid character\n"));
        }
    }
    return (MY_EXIT_SUCCESS);
}

char *error_handling(int ac, const char **av)
{
    char *maze_1d;

    if (display_usage(ac, av)) {
        return (NULL);
    }
    if (ac != 2) {
        return (print_error(1, NULL, \
"ERROR: Incorrect number of arguments.\n"));
    }
    maze_1d = file_to_str(av[1]);
    if (valid_maze(maze_1d)) {
        free(maze_1d);
        return (NULL);
    }
    return (maze_1d);
}
