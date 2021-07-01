/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main_criterion(int argc, char **argv);

Test(suite_name, uno) {
    char **tab = malloc(sizeof(char *) * 2);

    tab[0] = "coucou";
    tab[1] = "12";
    cr_redirect_stdout();
    main_criterion(2, tab);
    cr_assert_stdout_eq_str("\n");
}

Test(suite_name, sorted) {
    char **tab = malloc(sizeof(char *) * 4);

    tab[0] = "coucou";
    tab[1] = "12";
    tab[2] = "13";
    tab[3] = "25";
    cr_redirect_stdout();
    main_criterion(4, tab);
    cr_assert_stdout_eq_str("\n");
}

Test(suite_name, all) {
    char **tab = malloc(sizeof(char *) * 6);

    tab[0] = "coucou";
    tab[1] = "5";
    tab[2] = "3";
    tab[3] = "4";
    tab[4] = "2";
    tab[5] = "1";
    cr_redirect_stdout();
    main_criterion(6, tab);
    cr_assert_stdout_eq_str("rra pb rra pb ra pb pb pb pa pa pa pa pa\n");
}

Test(suite_name, none) {
    char **tab = malloc(sizeof(char *) * 2);

    tab[0] = "coucou";
    cr_assert(main_criterion(1, tab) == 84);
}

Test(suite_name, neg) {
    char **tab = malloc(sizeof(char *) * 4);

    tab[0] = "coucou";
    tab[1] = "-7";
    tab[2] = "9";
    tab[3] = "0";
    cr_redirect_stdout();
    main_criterion(4, tab);
    cr_assert_stdout_eq_str("pb ra pb pb pa pa pa\n");
}