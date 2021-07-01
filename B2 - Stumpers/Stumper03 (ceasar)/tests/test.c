/*
** EPITECH PROJECT, 2021
** [Stumper_template]
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"

Test(suite_name, check_getnbr)
{
    int nb = my_getnbr("3");

    cr_assert_eq(nb, 3);
}

Test(suite_name, check_getnbr_neg)
{
    int nb = my_getnbr("-3");

    cr_assert_eq(nb, -3);
}

Test(suite_name, check_getnbr_zero)
{
    int nb = my_getnbr("0");

    cr_assert_eq(nb, 0);
}

Test(suite_name, check_getnbr_null)
{
    int nb = my_getnbr(NULL);

    cr_assert_eq(nb, 0);
}

Test(suite_name, test1)
{
    char *word = load_file("src/main.c");
}

Test(suite_name, check_str_isnum_true)
{
    int nb = my_str_isnum("3");

    cr_assert_eq(nb, 1);
}

Test(suite_name, check_str_isnum_false)
{
    int nb = my_str_isnum("aA");

    cr_assert_eq(nb, 0);
}

Test(suite_name, get_error_1)
{
    char *argv[4] = {"plop", "-s", "plop", "10"};
    int nb = get_error(4, argv);

    cr_assert_eq(nb, 0);
}

Test(suite_name, get_error_2)
{
    char **argv = NULL;
    int nb = get_error(4, argv);

    cr_assert_eq(nb, 1);
}

Test(suite_name, get_error_3)
{
    char *argv[4] = {"plop", "-zdz", "plop", "10"};
    int nb = get_error(4, argv);

    cr_assert_eq(nb, 1);
}

Test(suite_name, get_error_4)
{
    char *argv[4] = {"plop", "-f", "plop", "10"};
    int nb = get_error(6, argv);

    cr_assert_eq(nb, 1);
}

Test(suite_name, get_error_5)
{
    char *argv[4] = {"plop", "-f", "plop", "-10"};
    int nb = get_error(4, argv);

    cr_assert_eq(nb, 0);
}

Test(suite_name, get_error_6)
{
    char *argv[4] = {"plop", "-f", "plop", "-fqzfz"};
    int nb = get_error(4, argv);

    cr_assert_eq(nb, 1);
}

Test(suite_name, get_error_7)
{
    char *argv[4] = {"plop", "-f", "plop", "f"};
    int nb = get_error(4, argv);

    cr_assert_eq(nb, 1);
}