/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** read_file
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *fs_cat_x_bytes(char const *filepath, int x)
{
    char *buffer = malloc(sizeof(char) * x + 1);
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, x);
    close(fd);
    return buffer;
}

char *load_file(char const *filepath)
{
    struct stat buf;

    stat(filepath, &buf);
    return fs_cat_x_bytes(filepath, buf.st_size);
}

int size_file(char const *filepath)
{
    struct stat buf;

    stat(filepath, &buf);
    return buf.st_size;
}