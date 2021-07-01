/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse a string3
*/

int foo(char *str)
{
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

char *my_revstr(char *str)
{
    int len = foo(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    return str;
}

