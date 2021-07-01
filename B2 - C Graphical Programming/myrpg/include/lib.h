/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-arthur.decaen
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

char *clonestr(char *txt);
int my_in(char want, char *source);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_itos(int value, int base);
void my_putstr(char const *str);
char *my_revstr(char *str);
int my_getnbr(char const *str);
int my_put_nbr(int nb);
int my_strncmp(char *env, char *search);
int len_array(char **array);
int my_str_isnum(char const *str);

#endif