/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** check_file
*/

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "lib.h"

int check_file(char *filepath)
{
    int file;

    if ((file = open(filepath, O_RDONLY)) == -1) {
        my_putstr("Fichier non trouvé.\n");
        return 1;
    }
    close(file);
    return 0;
}

int index_function(char elem)
{
    char possible[4] = {'1', '2', '3', 0};

    for (int i = 0; possible[i] != 0; i++) {
        if (possible[i] == elem)
            return i;
    }
    return -1;
}

char *get_content(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat file;
    char *content;
    int read_assert;

    stat(path, &file);
    content = malloc(file.st_size);
    read_assert = read(fd, content, file.st_size);
    if (read_assert == -1)
        return NULL;
    close(fd);
    return content;
}
