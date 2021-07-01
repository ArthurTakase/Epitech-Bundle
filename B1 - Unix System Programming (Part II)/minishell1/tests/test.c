/*
** EPITECH PROJECT, 2021
** B-PSU-101-BDX-1-1-minishell1-arthur.decaen
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"

Test(suite_name, clone) {
    char *word = clonestr("salut");

    cr_assert_str_eq(word, "salut");
}

Test(suite_name, nb_word) {
    int nb = get_word("salut les amis");

    cr_assert_eq(nb, 3);
}

Test(suite_name, comp) {
    int nb = my_strcmp("salut", "salut");

    cr_assert_eq(nb, 0);
}

Test(suite_name, putstr) {
    cr_redirect_stdout();
    my_putstr("salut");
    cr_assert_stdout_eq_str("salut");
}

Test(suite_name, split_char) {
    char *txt = "exit";
    char **split_char = split(txt);

    cr_assert_str_eq(split_char[0], "exit");
}

/*
Test(suite_name, echo2) {
    cr_redirect_stdout();
    main_function(2, " \tHello\t\t how are you?\t ");
    cr_assert_stdout_eq_str("Hello how are you?\n");
}*/