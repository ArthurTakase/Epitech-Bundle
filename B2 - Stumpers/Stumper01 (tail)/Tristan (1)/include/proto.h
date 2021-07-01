/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** .h principal au programme
*/

#ifndef PROTO_H_
#define PROTO_H_

typedef struct s_tail
{
    int c;
    int n;
    int q;
    char signe;
    char letter;
    char *file;
} tail_t;

int stumper(int argc, char **argv);
void check_flag(char **argv, char **flags, int i, int j);
void add_value(int j, int value, tail_t *s_tail);
void change_value(tail_t *s_tail, char **argv, int i, int k);
void check_number(char **argv, int i, int k, int j);

#endif