/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** lib
*/

#ifndef LIB_H_
#define LIB_H_

int my_in(char want, char *source);
int how_many_in(char *source, char *want);
char **split_str(char *str, char *separator);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2);
int len_array(char **array);
char *my_strcat(char *dest, char const *src);

#endif /* !LIB_H_ */
