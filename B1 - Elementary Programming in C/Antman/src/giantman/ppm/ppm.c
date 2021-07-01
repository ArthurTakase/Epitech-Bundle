/*
** EPITECH PROJECT, 2021
** antman
** File description:
** ppm
*/

#include <stdlib.h>
#include <unistd.h>
#include "giantman.h"
#include "common.h"
#include "lib.h"

int print_comment(char **file)
{
    char nbr = file[0][0];

    my_putstr("P3\n");
    write(1, ++file[0], nbr);
    my_putstr("\n");
    file[0] += nbr;
    return nbr;
}

void print_dims(char **file)
{
    int width = 0;
    int height = 0;
    char *w = malloc(8);
    char *h = malloc(8);

    width |= file[0][1];
    width  = width << 8;
    width |= file[0][0];
    height |= file[0][3];
    height = height << 8;
    height |= file[0][2];
    w = itos_base(width, 10);
    h = itos_base(height, 10);
    write(1, w, my_strlen(w));
    my_putstr(" ");
    write(1, h, my_strlen(h));
    my_putstr("\n");
    file[0] += 4;
}

void print_values(unsigned char *file, int nbr, char *path)
{
    int end = size_file(path) - nbr - 5;

    for (int i = 0; i < end; i++) {
        my_putstr(my_itos((int)file[i], 10));
        my_putstr("\n");
    }
}

void decompress_ppm(char *file)
{
    int nbr;

    unsigned char *ppm = (unsigned char *)load_file(file);
    nbr = print_comment(&ppm);
    print_dims(&ppm);
    print_values(ppm, nbr, file);
}