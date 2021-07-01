/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int len = 0;
    char tmp;

    while (str[len] != '\0')
        len++;
    len--;
    for (int i = 0; i < len; i++) {
        tmp = str[len];
        str[len] = str[i];
        str[i] = tmp;
        len--;
    }
    return str;
}
