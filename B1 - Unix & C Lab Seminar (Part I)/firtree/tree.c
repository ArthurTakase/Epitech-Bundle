/*
** EPITECH PROJECT, 2020
** fir tree
** File description:
** display a fir tree based on a given size
*/

#include <unistd.h>

void my_putchar(char c);

// Print chaque ligne de l'arbre
void print_line_tree(int nb_star, int len_last)
{
    for (int i = 0; i != (len_last - nb_star) / 2; i++) {
        my_putchar(' ');
    }
    for (int k = 0; k != nb_star; k++) {
        my_putchar('*');
    }
}

// Print chaque partie de l'arbre
int print_part_tree(int *arg)
{
    int size = arg[0];
    int nb_star = arg[1];
    int i = arg[2];
    int flag = arg[3];
    int len_last = arg[4];

    for (int j = 0; j != 4 - size + (size + i); j++) {
        nb_star += 2;
        if (flag == 1) {
            print_line_tree(nb_star, len_last);
            my_putchar('\n');
        }
    }
    return nb_star;
}

// Print l'arbre au complet
int print_tree(int len_last, int size, int flag)
{
    int delet = 2;
    int nb_star = -1;
    int arg[5];

    for (int i = 0; i != size; i++) {
        arg[0] = size;
        arg[1] = nb_star;
        arg[2] = i;
        arg[3] = flag;
        arg[4] = len_last;
        nb_star = print_part_tree(arg);
        if (i % 2 == 0) {
            delet += 2;
        }
        nb_star -= delet;
    }
    return nb_star += delet;
}

// Print le tronc
void tronc(int len_last, int size)
{
    int limit = 0;

    if (size % 2 == 0) {
        size++;
        limit = 1;
    }
    len_last = (len_last / 2) - (size / 2);
    for (int i = 0; i != size - limit; i++) {
        for (int x = 0; x != len_last; x++) {
            my_putchar(' ');
        }
        for (int k = 0; k != size; k++) {
            my_putchar('|');
        }
        my_putchar('\n');
    }
}

// generation sapin
void tree(int size)
{
    int flag = 0;
    int len_last = 0;

    if (size > 0){
        len_last = print_tree(len_last, size, flag);
        flag++;
        print_tree(len_last, size, flag);
        tronc(len_last, size);
    } else {
        write(2, "Invalid size\n", 13);
    }
}
