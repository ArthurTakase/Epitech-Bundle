/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** stumper
*/

#include "proto.h"
#include "lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>

int stumper(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    char *flags[10] = {"-c", "--bytes", "-n",
                    "--lines", "-q", "--quiet",
                    "--silent", "-v", "--verbose", NULL};
    while (argv[i] != NULL) {
        while (flags[j] != NULL) {
            check_flag(argv, flags, i, j);
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
    return 0;
}

void check_flag(char **argv, char **flags, int i, int j)
{
    int k;

    if (my_strncmp(argv[i], flags[j], my_strlen(flags[j])) == 0) {
        k = my_strlen(flags[j]);
        if (argv[i][k] == '\0') {
            i = i + 1;
            k = 0;
            check_number(argv, i, k, j);
        }
        check_number(argv, i, k, j);
    }
}

void check_number(char **argv, int i, int k, int j)
{
    int value;
    tail_t s_tail;

    if (argv[i][k] == '+') {
        s_tail.signe = '+';
        k = k + 1;
    }
    if (argv[i][k] == '-') {
        s_tail.signe = '-';
        k = k + 1;
    }
    if (argv[i][k] <= '9' && argv[i][k] >= '0') {
        value = my_getnbr(argv[i]);
        add_value(j, value, &s_tail);
        k = k + 1;
    }
    if (argv[i][k] <= 'z' && argv[i][k] >= 'a')
        change_value(&s_tail, argv, i, k);
}

void change_value(tail_t *s_tail, char **argv, int i, int k)
{
    if (argv[i][k] == 'b') {
        if (s_tail->letter == 'c')
            s_tail->c = s_tail->c * 512;
        if (s_tail->letter == 'n')
            s_tail->n = s_tail->n *512;
    }
    if (argv[i][k] == 'k') {
        if (s_tail->letter == 'c')
            s_tail->c = s_tail->c * 512 * 1024;
        if (s_tail->letter == 'n')
            s_tail->n = s_tail->n *512 * 1024;
    }
    if (argv[i][k] == 'm') {
        if (s_tail->letter == 'c')
            s_tail->c = s_tail->c * 512 * 1024 * 1024;
        if (s_tail->letter == 'n')
            s_tail->n = s_tail->n *512 * 1024 * 1024;
    }

}

void add_value(int j, int value, tail_t *s_tail)
{
    if (j < 2) {
        s_tail->c = value;
        s_tail->letter = 'c';
    }
    if (j > 1 && j < 4) {
        s_tail->n = value;
        s_tail->letter = 'n';
    }
    if (j > 3 && j < 7)
        s_tail->q = 0;
    if (j > 6)
        s_tail->q = 1;
}
