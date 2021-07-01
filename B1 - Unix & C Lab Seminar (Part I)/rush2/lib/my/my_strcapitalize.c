/*
** EPITECH PROJECT, 2020
** my_capitalize
** File description:
** capitalize the first letter of each word
*/

char *my_strlowcase(char *str);

void modif_str(char *str, int i)
{
    if (str[i + 1] >= 97 && str[i + 1] <= 122) {
        if (i == 0)
            str[i] -= 32;
    }
    if (str[i + 1] >= 97 && str[i + 1] <= 122) {
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
            str[i + 1] -= 32;
    }
}

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i + 1] == '\0')
            return str;
        modif_str(str, i);
    }
    return str;
}
