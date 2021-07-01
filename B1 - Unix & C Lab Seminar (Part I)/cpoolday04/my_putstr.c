/*
** EPITECH PROJECT, 2020
** my_pustr.c
** File description:
** displat chacter of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{

    for (int count = 0; str[count] != '\0'; count++) {
        my_putchar(str[count]);
    }
    return 0;
}
