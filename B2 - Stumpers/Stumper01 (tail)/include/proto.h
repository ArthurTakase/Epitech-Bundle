/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** .h principal au programme
*/

#ifndef PROTO_H_
#define PROTO_H_

#define BUFFER 20900000000

typedef struct s_list_file
{
    char *file;
    struct s_list_file *next;
} list_file_t, *file_t;

typedef struct s_tail
{
    int n;
    int q;
    char letter;
    char signe;
    file_t files;
} tail_t;

int stumper(int argc, char **argv);
int tail_function(tail_t *tail);
int tail_all(tail_t *tail, char *buffer);
file_t new_list(void);
file_t push_back_list(file_t li, char *value);
file_t new_list(void);
int is_empty_list(file_t li);

#endif