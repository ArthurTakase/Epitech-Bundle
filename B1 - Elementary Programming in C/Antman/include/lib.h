/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-arthur.decaen
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
void my_putstr(char const *str);
int my_get_nbr(char *str);
char *itos_base(int n, int base);
char *my_strncat(char *dest, const char *src, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *load_file(char const *filepath);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_itos(int value, int base);

#endif