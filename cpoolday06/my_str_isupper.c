/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** only contain letter
*/

int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    int len = my_strlen(str);

    if (len == 0)
        return 1;
    for (int j = 0; j != len - 1; j++ ) {
        if (str[j] < 65  || str[j] > 90)
            return 0;
    }
    return 1;
}
