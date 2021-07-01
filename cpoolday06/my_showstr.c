/*
** EPITECH PROJECT, 2020
** my_showstr.c
** File description:
** print string witch only printable char
*/

void my_putchar(char c);

int my_putnbr_base(int nbr, char const *base);

int my_showstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < ' ') {
            my_putchar('\\');
            my_putchar('0');
            my_putnbr_base((int)str[i], "0123456789abcdef");
        } else {
            my_putchar(str[i]);
        }
    }
    return 0;
}
