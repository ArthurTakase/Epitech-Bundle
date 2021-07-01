/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** giantman
*/

#ifndef GIANTMAN_H_
#define GIANTMAN_H_

typedef struct list_element
{
    char *elem;
    int value;
    struct list_element *next;
} list_element_t, *list_t;

int check_h(int argc, char **argv);
int giant_h(void);
int check_file(char *filepath);
int index_function(char elem);
void html_compress(char *filepath);

list_t new_list(void);
list_t push_back_list(list_t li, char *value);
list_t init_list(char *txt);
list_t push_back_list_int(list_t li, int value);
list_t clear_list(list_t li, int flag);
list_t pop_front_list(list_t li, int flag);

void txt_function(char *file);
char *clonestr(char *txt);
char *strfromchar(char letter);
int size_file(char const *filepath);
int in_list(char *txt, list_t liste);

list_t get_all_number(char *txt, char *filepath);
int get(list_element_t **liste);
char *in_list_int(int index, list_t liste);

// -----------------decompress-----------------
void decompress_ppm(char *file);

#endif