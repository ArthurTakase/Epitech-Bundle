/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** print reverse alphabet
*/

int my_putchar(char c);

int my_print_revalpha(void)
{
    for (int letter = 122; letter > 96; letter--) {
        my_putchar(letter);
    }
    my_putchar('\n');
    return (0);
}
