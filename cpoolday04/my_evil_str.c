/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** inverse str
*/

int my_strlen(char const *str);

void swap_char(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_evil_str(char *str)
{
    int len = my_strlen(str);
    int count = 0;

    while (count < len / 2){
        swap_char(str + count, str + len - count - 1);
        count++;
    }
    return str;
}
