/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** tout en majuscule
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    return str;
}
