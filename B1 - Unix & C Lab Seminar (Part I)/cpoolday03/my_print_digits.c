/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** display number
*/

int my_putchar(char c);

int my_print_digits(void)
{
    for (int number = 48; number < 58; number++) {
        my_putchar(number);
    }
    my_putchar('\n');
    return 0;
}
