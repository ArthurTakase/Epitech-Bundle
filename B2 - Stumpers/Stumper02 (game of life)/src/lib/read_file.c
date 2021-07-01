/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-stumper2-arthur.decaen
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

    if (buffer == NULL)
        exit(84);
    if (fd == -1) {
        write(2 , "The requested file does not exist.\n", 36);
        free(buffer);
        exit(84);
    }
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