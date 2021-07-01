/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** antman
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_

typedef struct list_element
{
    char *elem;
    int value;
    struct list_element *next;
} list_element_t, *list_t;

int check_h(int argc, char **argv);
int ant_h(void);
int check_file(char *filepath);
int index_function(char elem);

char *get_content(char *path);
int len_2darray(char **array);
void html_compress(char *filepath);

void lzw_compress(char *txt);
char *strfromchar(char letter);
void print_bin(list_t result, list_t dict);
int in_list(char *txt, list_t liste);
char *clonestr(char *txt);
int size_file(char const *filepath);

void compress(char *file);

list_t new_list(void);
list_t push_back_list(list_t li, char *value);
list_t init_list(char *txt);
list_t push_back_list_int(list_t li, int value);
list_t clear_list(list_t li, int flag);
list_t pop_front_list(list_t li, int flag);

#endif
