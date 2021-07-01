/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** optionh
*/

#include "lib.h"

int check_h(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0)
            return 1;
    }
    return 0;
}

int giant_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("./giantman [filepath] [1-3]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("[filepath]\tLocation of file to decompress\n");
    my_putstr("[1-3]\t\tFile type\n");
    my_putstr("\t\t1 -> txt\n");
    my_putstr("\t\t2 -> html\n");
    my_putstr("\t\t3 -> ppm\n");
    return 0;
}

int ant_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("./antman [filepath] [1-3]\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("[filepath]\tLocation of file to compress\n");
    my_putstr("[1-3]\t\tFile type\n");
    my_putstr("\t\t1 -> txt\n");
    my_putstr("\t\t2 -> html\n");
    my_putstr("\t\t3 -> ppm\n");
    return 0;
}