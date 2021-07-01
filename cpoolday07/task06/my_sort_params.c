/*
** EPITECH PROJECT, 2020
** my_rev_param
** File description:
** print all param reverse
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_strcmp(char const *s1, char const *s2);

int my_sort_params(int argc, char **argv)
{
    char *temp;

    for (int i = 0; argc > i; i++) {
        for (int k = 0; k < argc - i - 1; k++) {
            if (my_strcmp(argv[k], argv[k + 1]) > 0) {
                temp = argv[k];
                argv[k] = argv[k + 1];
                argv[k + 1] = temp;
            }
        }
    }
    for (int j = 0; argc > j; j++) {
        my_putstr(argv[j]);
        my_putchar('\n');
    }
    return 0;
}

int main(int argc, char **argv)
{
    my_sort_params(argc, argv);
    return 0;
}
