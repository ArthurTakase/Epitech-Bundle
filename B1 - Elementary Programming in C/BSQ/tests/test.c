/*
** EPITECH PROJECT, 2020
** temp_printf
** File description:
** tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int start(char *argv);

Test(suite_name, 5x5) {
    start("tests/map");
    cr_redirect_stdout();
    start("tests/map");
    cr_assert_stdout_eq_str(".oxx.\no.xxo\n.....\n.oo.o\n..o.o\n");
}

Test(suite_name, 5x5_empty) {
    start("tests/map_empty");
    cr_redirect_stdout();
    start("tests/map_empty");
    cr_assert_stdout_eq_str("xxxxx\nxxxxx\nxxxxx\nxxxxx\nxxxxx\n");
}

Test(suite_name, 5x1_empty_column) {
    cr_redirect_stdout();
    start("tests/map_empty_column");
    cr_assert_stdout_eq_str("x....\n");
}

Test(suite_name, 1x5_empty_line) {
    cr_redirect_stdout();
    start("tests/map_empty_line");
    cr_assert_stdout_eq_str("x\n.\n.\n.\n.\n");
}

Test(suite_name, 5x5_filled) {
    start("tests/map_filled");
    cr_redirect_stdout();
    start("tests/map_filled");
    cr_assert_stdout_eq_str("ooooo\nooooo\nooooo\nooooo\nooooo\n");
}