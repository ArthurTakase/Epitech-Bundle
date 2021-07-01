/*
** EPITECH PROJECT, 2020
** my_rev_param
** File description:
** print all param reverse
*/

void my_putchar(char c);

int my_putstr(char const *str);

void print_rev_params(int argc, char **argv)
{
    for (int i = argc - 1; i >= 0; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    print_rev_params(argc, argv);
    return (0);
}
