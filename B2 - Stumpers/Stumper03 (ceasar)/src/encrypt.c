/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-stumper3-arthur.decaen
** File description:
** decrypt
*/

#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int get_error(int argc, char **argv)
{
    if (argv == NULL)
        return 1;
    if (argc != 4) {
        write(2 , "Bad number of arguments.\n", 26);
        return 1;
    }
    if (strcmp(argv[1], "-f") && strcmp(argv[1], "-s")) {
        write(2 , "Wrong argument 1 (-f or -s).\n", 30);
        return 1;
    }
    if (!my_str_isnum(argv[3])) {
        if (strlen(argv[3]) != 1 && my_str_isnum(argv[3] + 1)
            && argv[3][0] == '-')
            return 0;
        write(2 , "The last argument is not a number.\n", 36);
        return 1;
    }
    return 0;
}

char *encrypt_cesar(char *file, int key)
{
    if (file == NULL)
        exit(84);
    for (int i = 0; file[i] != '\0'; i++) {
        if (!isalpha(file[i]))
            continue;
        else if (isupper(file[i]))
            file[i] = (file[i] + key - 65) % 26 + 65;
        else
            file[i] = (file[i] + key - 97) % 26 + 97;
    }
    return file;
}

void write_in_file(char *to_write)
{
    FILE *fd;
    int chmod_value = chmod("crypt", S_IWUSR | S_IWGRP | S_IWOTH);

    fd = fopen("crypt", "w");
    if (chmod_value == -1)
        chmod("crypt", S_IWUSR | S_IWGRP | S_IWOTH);
    fwrite(to_write, 1, strlen(to_write), fd);
    fclose(fd);
    chmod("crypt", S_IRUSR | S_IRGRP | S_IROTH);
}

int encrypt(int argc, char **argv)
{
    char *file;
    int key;

    if (get_error(argc, argv))
        return 84;
    key = my_getnbr(argv[3]);
    if (key < 0)
        key = 26 + (key % 26);
    if (!strcmp(argv[1], "-s"))
        file = argv[2];
    else
        file = load_file(argv[2]);
    file = encrypt_cesar(file, key);
    write_in_file(file);
    if (!strcmp(argv[1], "-f"))
        free(file);
    return 0;
}