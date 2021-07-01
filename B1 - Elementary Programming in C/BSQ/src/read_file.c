/*
** EPITECH PROJECT, 2020
** Bootstrap BSQ
** File description:
** step3.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Read x byte of a file
char *fs_cat_x_bytes(char const *filepath, int x)
{
    char *buffer = malloc(sizeof(char) * x + 1);
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, x);
    close(fd);
    return buffer;
}
