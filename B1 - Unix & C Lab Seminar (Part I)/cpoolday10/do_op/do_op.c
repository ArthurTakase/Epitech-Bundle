/*
** EPITECH PROJECT, 2020
** do op
** File description:
** do op
*/

#include "../include/my.h"
#include <unistd.h>

int my_add(int i, int j);

int my_sub(int i, int j);

int my_div(int i, int j);

int my_mul(int i, int j);

int my_mod(int i, int j);

int my_char_isalpha(char **argv, int i)
{
    if (argv[i][0] >= 48 &&  argv[i][0] <= 57)
        return 1;
    if (argv[i][0] == '-')
        return 1;
    return 0;
}

int get_error(int argc, char **argv)
{
    char operators[5] = {'+', '-', '/', '%', '*'};

    if (argc < 4)
        return 84;
    if (argv[2][0] == '/' && (my_getnbr(argv[1]) == 0 ||
        my_getnbr(argv[3]) == 0)) {
        my_putchar('0');
        return 84;
    }
    if (argv[2][0] == '%' && (my_getnbr(argv[1]) == 0 ||
        my_getnbr(argv[3]) == 0)) {
        my_putchar('0');
        return 84;
    }
    for (int i = 0; i < 5; i++) {
        if (argv[2][0] == operators[i])
            return 1;
    }
    my_putchar('0');
    return 84;
}

int calcul_def(char **argv)
{
    int i = my_getnbr(argv[1]);
    int j = my_getnbr(argv[3]);
    char op = argv[2][0];

    if (my_char_isalpha(argv, 1) == 0)
        i = 0;
    if (my_char_isalpha(argv, 3) == 0)
        j = 0;
    if (op == '+')
        return my_add(i, j);
    if (op == '-')
        return my_sub(i, j);
    if (op == '/')
        return my_div(i, j);
    if (op == '*')
        return my_mul(i, j);
    if (op == '%')
        return my_mod(i, j);
}

int main(int argc, char **argv)
{
    int result;

    if (get_error(argc, argv) != 1)
        return 84;
    result = calcul_def(argv);
    my_put_nbr(result);
    return 0;
}
