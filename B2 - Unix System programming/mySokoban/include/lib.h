/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** Proto des lib utilisées dans le programme
*/

#ifndef LIB_H_
#define LIB_H_

char *itos_base(int n, int base);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *load_file(char const *filepath);
int my_strlen(char const *str);
int my_in(char want, char *source);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);

#endif