/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** find str in an other
*/

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; str[j + i] == to_find[j]; j++) {
            if (to_find[j + 1] == '\0')
                return (&str[i]);
        }
    }
    return 0;
}
