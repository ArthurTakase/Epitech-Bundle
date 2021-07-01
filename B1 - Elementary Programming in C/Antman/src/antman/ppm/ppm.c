/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** ppm
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "common.h"
#include "lib.h"

void print_text(char **);

unsigned char getnbr(int *n, char *str)
{
    int nbr = 0;
    int count = 0;

    while (*str < 58 && *str > 47) {
        nbr += (*str - 48);
        nbr *= 10;
        count++;
        str++;
    }
    *n = count + 1;
    return (unsigned char)(nbr / 10);
}

int getnbr_i(int *n, char *str)
{
    int nbr = 0;
    int count = 0;

    while (*str < 58 && *str > 47) {
        nbr += (*str - 48);
        nbr *= 10;
        count++;
        str++;
    }
    *n = count + 1;
    return (nbr / 10);
}

int get_line_nbr(char *path)
{
    int line = 0;
    char *ppm = load_file(path);

    for (int i = 0; ppm[i] != 0; i++) {
        if (ppm[i] == 10)
            line++;
    }
    return line;
}

void print_dims(char **str)
{
    int n;
    int dim;
    int len;

    for (int i = 0; i < 2; i++) {
        dim = getnbr_i(&n, str[0]);
        write(1, &dim, 2);
        str[0] += n;
    }
}

void compress(char *file)
{
    int line = get_line_nbr(file);
    unsigned char *data = malloc(sizeof(unsigned char) * line);
    char *ppm = load_file(file);
    char *tmp = ppm;
    int n = 0;
    int count = 0;

    print_text(&ppm);
    print_dims(&ppm);
    for (int i = 0; i < line - 3; i++) {
        data[i] = getnbr(&n, ppm);
        ppm += n;
    }
    write(1, data, line - 3);
    free(data);
    free(tmp);
}

