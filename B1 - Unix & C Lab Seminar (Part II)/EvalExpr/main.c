/*
** EPITECH PROJECT, 2020
** Eval expr
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/eval.h"

int prio(int number, char **str)
{
    if (str[0][0] != ')' && str[0][0])
        number += do_op_rec(str, int_to_char(str[0] + 1, str));
    return number;
}

int do_op_rec(char **str, int number)
{
    if (str[0][0] != '\0') {
        if (str[0][0] == '(')
            number = do_op_rec(str, prio(number, str));
        if (str[0][0] == '*')
            number *= do_op_rec(str, int_to_char(str[0] + 1, str));
        if (str[0][0] == '/')
            number /= do_op_rec(str, int_to_char(str[0] + 1, str));
        if (str[0][0] == '+')
            number += do_op_rec(str, int_to_char(str[0] + 1, str));
        if (str[0][0] == '-')
            number -= do_op_rec(str, int_to_char(str[0] + 1, str));
        if (str[0][0] == '%')
            number %= do_op_rec(str, int_to_char(str[0] + 1, str));
        if (str[0][0] == ')')
            number += do_op_rec(str + 1, int_to_char(str[0] + 1, str));
    }
    return number;
}

int eval_expr(char *str)
{
    char **end;
    int number = 0;

    end = &str;
    number = int_to_char(end[0], end);
    return do_op_rec(end, number);
}

int main(int argc , char **argv)
{
    if (argc == 2) {
        my_put_nbr(eval_expr(argv[1]));
        my_putchar('\n');
        return 0;
    }
    write(2, "Invalid arguments\n", 18);
    return 84;
}
