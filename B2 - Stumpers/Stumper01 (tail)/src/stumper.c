/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** stumper
*/

#include "proto.h"
#include "lib.h"
#include <stdlib.h>
#include <fcntl.h>

int tail_function(tail_t *tail);

int in_tab(char *what, char **in, int choice)
{
    for (int i = 0; in[i] != 0; i++) {
        if (choice == 0 && !my_strcmp(what, in[i]))
            return i;
        if (choice == 1 && !my_strncmp(what, in[i], my_strlen(in[i])))
            return i;
    }
    return -1;
}

int get_number(int len_flag, char *arg, tail_t *tail)
{
    int flag = 0;

    switch (arg[len_flag]) {
        case '+':
            tail->signe = '+';
            flag++;
            break;
        case '-':
            tail->signe = '-';
            flag++;
            break;
    }
    if (my_in(arg[my_strlen(arg) - 1], "bmk"))
        my_putstr(" -> special\n");
    else if (my_str_isnum(arg + len_flag + flag))
        tail->n = my_getnbr(arg + len_flag + flag);
    else
        return 84;
    return 0;
}

int check_number(char *arg, char *n_arg, char *flag, tail_t *tail)
{
    int len_flag = my_strlen(flag);

    if (arg[1] == 'c' || arg[2] == 'b')
        tail->letter = 'c';
    else
        tail->letter = 'n';
    if (len_flag == my_strlen(arg)) {
        if (get_number(0, n_arg, tail) == 84)
            return 84;
        return 1;
    }
    if (get_number(my_strlen(flag), arg, tail) == 84)
        return 84;
    return 0;
}

void set_prompt(char *prompt, tail_t *tail)
{
    if (prompt[1] == 'v' || prompt[2] == 'v')
        tail->q = 1;
    else
        tail->q = 0;
}

int stumper(int argc, char **argv)
{
    tail_t tail;
    int flag;
    char *flags[10] = {"-c", "--bytes", "-n", "--lines", 0};
    char *prompt[6] = {"-q", "--quiet", "--silent", "-v", "--verbose", 0};

    tail.files = new_list();
    tail.signe = '-';
    tail.n = 10;
    for (int i = 1; i < argc; i++) {
        if ((flag = in_tab(argv[i], flags, 1)) != -1) {
            i += check_number(argv[i], argv[i + 1], flags[flag], &tail);
            continue;
        }
        if ((flag = in_tab(argv[i], prompt, 0)) != -1)
            set_prompt(prompt[flag], &tail);
        else if ((flag = open(argv[i], O_RDONLY)) != -1)
            tail.files = push_back_list(tail.files, argv[i]);
        else
            return 84;
    }

    printf("n: %d\nletter: %c\nq: %d\nsigne: %c\nFile: ", tail.n, tail.letter, tail.q, tail.signe);
    while (tail.files != NULL)
    {
        printf("%s, ", tail.files->file);
        tail.files = tail.files->next;
    }

    tail_function(&tail);

    return 0;
}