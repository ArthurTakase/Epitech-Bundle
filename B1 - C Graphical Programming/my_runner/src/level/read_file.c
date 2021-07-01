/*
** EPITECH PROJECT, 2020
** myrunner
** File description:
** read_file
*/

#include "struct.h"

int get_error(char *filepath)
{
    int file;

    if ((file = open(filepath, O_RDONLY)) == -1)
        return 1;
    close(file);
    return 0;
}

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
    struct stat *buf;

    buf = malloc(sizeof(struct stat));
    stat(filepath, buf);
    return fs_cat_x_bytes(filepath, buf->st_size);
}

int check_file(char *argv)
{
    if (get_error(argv)) {
        my_putstr("Fichier non trouvé.\n");
        return 1;
    }
    return 0;
}