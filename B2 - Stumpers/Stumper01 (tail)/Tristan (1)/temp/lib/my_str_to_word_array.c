/*
** EPITECH PROJECT, 2020
** my str to word array
** File description:
** my str to word array
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n);

int is_alphanum(char str)
{
    if ((str >= 97 && str <= 122) || (str >= 65 && str <= 90)) {
        return 1;
    } else if (str >= 48 && str <= 57) {
        return 1;
    }
    return 0;
}

int count_words(char const *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 1 && is_alphanum(str[i + 1]) == 0)
            len++;
    }
    return len;
}

char **my_str_to_word_array(char const *str)
{
    char **dest = malloc(sizeof(char *) * (count_words(str) + 1));
    int len = 0;
    int j = 0;

    if (dest == 0)
        return 0;

    for (int i = 0; str != 0  && str[i] != '\0'; i++) {
        if (is_alphanum(str[i]))
            len++;
        if (is_alphanum(str[i]) && is_alphanum(str[i+1]) == 0) {
            dest[j] = malloc(len + 1);
            my_strncpy(dest[j], &str[i - len + 1], len);
            len = 0;
            j++;
        }
    }
    dest[j] = 0;
    return dest;
}
