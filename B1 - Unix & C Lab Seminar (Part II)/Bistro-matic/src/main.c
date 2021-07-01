/*
** EPITECH PROJECT, 2020
** Eval expr
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/eval.h"
#include "../include/calc.h"

int do_op_rec(char **str, int number, char **argv);

void get_error(char *buff, int argc, char **argv);

char *number_before(char *argv, int index);

char *number_after(char *argv, int index);

int prio(int number, char **str, char **argv)
{
    if (str[0][0] != argv[2][1])
        number += do_op_rec(str, my_strtol(str[0] + 1, str), argv);
    return number;
}

int do_op_rec(char **str, int number, char **argv)
{
    if (str[0][0] != '\0') {
        if (str[0][0] == argv[2][0])
            number = do_op_rec(str, prio(number, str, argv), argv);
        if (str[0][0] == argv[2][4])
            number *= do_op_rec(str, my_strtol(str[0] + 1, str), argv);
        if (str[0][0] == argv[2][5])
            number /= do_op_rec(str, my_strtol(str[0] + 1, str), argv);
        if (str[0][0] == argv[2][2])
            number += do_op_rec(str, my_strtol(str[0] + 1, str), argv);
        if (str[0][0] == argv[2][3])
            number -= do_op_rec(str, my_strtol(str[0] + 1, str), argv);
        if (str[0][0] == argv[2][6])
            number %= do_op_rec(str, my_strtol(str[0] + 1, str), argv);
        if (str[0][0] == argv[2][1])
            number += do_op_rec(str + 1, my_strtol(str[0] + 1, str), argv);
    }
    return number;
}

int eval_expr(char *str, char **argv)
{
    char **end;
    int number = 0;

    end = &str;
    number = my_strtol(end[0], end);
    return do_op_rec(end, number, argv);
}

int set_calc(char *argv, char *buff)
{
    int count = 0;

    for (int i = 2; argv[i] != '\0'; i++)
        count += my_howmanyin(argv[i], buff);
    if (count != 1)
        return 0;
    for (int i = 1; buff[i] != '\0'; i++) {
        if (buff[i] == argv[2]) {
            my_putstr(calc_add(number_before(buff, i), number_after(buff, i)));
            return 1;
        }
        if (buff[i] == argv[4]) {
            my_putstr(mul(number_before(buff, i), number_after(buff, i)));
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    char *buff_cut = malloc(sizeof(char) * BUFF_SIZE + 1);
    int index;

    buff_cut = my_read_buff();
    get_error(buff_cut, argc, argv);
    buff_cut[my_getnbr(argv[3])] = '\0';
    if (set_calc(argv[2], buff_cut))
        return 0;
    my_putnbr_base(eval_expr(buff_cut, argv), argv[1]);
    return 0;
}
