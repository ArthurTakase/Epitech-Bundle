/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int gameoflife(int argc, char **argv);

Test(suite_name, bon_arguments) {
    char *test[3] = {"dayfdzy", "bonus/map", "2"};
    int nb = gameoflife(3, test);

    cr_assert_eq(nb, 0);
}

Test(suite_name, mauvais_nombre_d_arg) {
    char *test2[3] = {"dayfdzy", "mapjgjy", "2"};
    int nb = gameoflife(5, test2);

    cr_assert_eq(nb, 84);
}

Test(suite_name, gen_neg) {
    char *test3[3] = {"dayfdzy", "mapjgjy", "-1"};
    int nb = gameoflife(3, test3);

    cr_assert_eq(nb, 84);
}

Test(suite_name, stdout1) {
    char *test4[3] = {"dayfdzy", "bonus/map", "2"};

    printf("ceci permet de debug le test");
    cr_redirect_stdout();
    gameoflife(3, test4);
    cr_assert_stdout_eq_str("................\n\
................\n\
.....XXXXXX.....\n\
....X......X....\n\
...X........X...\n\
....X......X....\n\
.....XXXXXX.....\n\
................\n\
................\n\
................\n");
}