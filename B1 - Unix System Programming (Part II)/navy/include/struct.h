/*
** EPITECH PROJECT, 2020
** B-PSU-101-BDX-1-1-navy-arthur.decaen
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define HIT 1
#define MISS 2

typedef struct s_global {
    int pid_ad;
    int is_next;
    int is_start;
    char *coord;
    int index_coord;
    int is_hit;
    char **tab;
    char **tab_ad;
} global_t;

extern global_t *global;

// NAVY

int get_error(char *filepath);
int init(void);
int player1(char *filepath);
int player2(char *filepath, char *pid);
int left(int player);
int check_coord31(char *buffer);
int check_coord32(char *buffer);
void reset(void);
void show_all(void);
void show_tab(char **tab);
void start_p1(void);
void color_tab(char tab_cell, int j);
void edit_tab(void);
void wait_reception(void);
void wait_start(void);
void loop_p1(void);
void wait_response(void);
void set_boat(char *place);
void append_tab(char x, char y, char sym);
void sub_place(int index, char *place);
void send_value(char *coord);
void win(void);
char *load_file(char const *filepath);
char *fs_cat_x_bytes(char const *filepath, int x);
char *get_send_line(void);
char *is_touch(char *coord);
char **create_tab(void);
int number(char elem);
int letter(char elem);
int dot(char elem);
int jump(char elem);

// LIB

int my_putstr(char const *str);
int put_unsigned(unsigned int nb);
int my_in(char want, char *source);
int index_function(char *choice, char letter);
int my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int display_nbr(int nb, char n);
int my_getnbr(char const *str);
int display_unsigned(unsigned int nb, char n);
int put_unsigned(unsigned int nb);
void pr_majs(va_list *my_list);
void pr_cent(va_list *my_list);
void pr_c(va_list *my_list);
void pr_d(va_list *my_list);
void pr_s(va_list *my_list);
void pr_b(va_list *my_list);
void pr_o(va_list *my_list);
void pr_x(va_list *my_list);
void pr_majx(va_list *my_list);
void my_printf(char const *str, ...);
void pr_u(va_list *args);
char *my_strlowcase(char *str);
char *my_revstr(char *str);
char *my_itos(int value, int base);
char *my_itos(int value, int base);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
int my_strlen(char const *str);


#endif