/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen-master
** File description:
** load_file
*/

#include "struct.h"

// Read x byte of a file
char *fs_cat_x_bytes(char const *filepath, int x)
{
    char *buffer = malloc(sizeof(char) * x + 1);
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, x);
    close(fd);
    return buffer;
}

// Stores the data of a file in a char *
char *load_file(char const *filepath)
{
    struct stat *buf;

    buf = malloc(sizeof(struct stat));
    stat(filepath, buf);
    if (buf->st_size == 0)
        return "no";
    return fs_cat_x_bytes(filepath, buf->st_size);
}