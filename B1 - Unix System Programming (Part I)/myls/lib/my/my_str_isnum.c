/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** only contain letter
*/

int len_str_num(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++)
        len++;
    return len;
}

int my_str_isnum(char const *str)
{
    int len = len_str_num(str);

    if (len == 0)
        return 1;
    for (int j = 0; j != len - 1; j++ ) {
        if (str[j] < 48  || str[j] > 57)
            return 0;
    }
    return 1;
}
