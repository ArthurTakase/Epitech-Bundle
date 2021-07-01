/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** display alphabet in lowercase
*/

int my_putchar(char c);

int my_print_alpha(void)
{    
    for (int letter = 'a'; letter <= 'z'; letter++) {
        my_putchar(letter);
    }
    my_putchar('\n');
    return 0;
}
