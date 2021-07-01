/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#define line(void) my_putchar('\n')
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y) ((X) < (Y) ? (Y) : (X))

int my_strlen(char const *str);
void my_sort_int_array(int *array, int size);
void my_putstr(char const *str);
void my_putchar(char c);
void my_swap(int *a, int *b);
int len_nbr(int nb);
int my_in(char want, char *source);