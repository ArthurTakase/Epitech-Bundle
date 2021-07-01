/*
** EPITECH PROJECT, 2020
** my_print_param
** File description:
** print all param
*/

void my_putchar(char c);

int my_putstr(char const *str);

void print_all_params(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
}

int main(int argc, char **argv)
{
    print_all_params(argc, argv);
    return (0);
}
