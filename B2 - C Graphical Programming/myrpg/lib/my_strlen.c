/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** len of str
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return len;
}
