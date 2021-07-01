/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** find str in an other
*/

char *my_strstr2(char *str, char const *to_find, int i, int j)
{
    if (to_find[j + 1] == '\0')
        return (&str[i]);
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; str[j + i] == to_find[j]; j++) {
            my_strstr2(str, to_find, i, j);
        }
    }
    return 0;
}
