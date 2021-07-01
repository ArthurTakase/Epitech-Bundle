/*
** EPITECH PROJECT, 2020
** temp_printf
** File description:
** tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

void my_printf(char const *str, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, d, .init = redirect_all_std)
{
    my_printf("%d", 12);
    cr_assert_stdout_eq_str("12");
}

Test (my_printf, d0, .init = redirect_all_std)
{
    my_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
}

Test (my_printf, dneg, .init = redirect_all_std)
{
    my_printf("%d", -12);
    cr_assert_stdout_eq_str("-12");
}

Test (my_printf, s, .init = redirect_all_std)
{
    my_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, c, .init = redirect_all_std)
{
    my_printf("%c", 'a');
    cr_assert_stdout_eq_str("a");
}

Test (my_printf, pourcent, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test (my_printf, x, .init = redirect_all_std)
{
    my_printf("%x", 123456);
    cr_assert_stdout_eq_str("1e240");
}

Test (my_printf, X, .init = redirect_all_std)
{
    my_printf("%X", 123456);
    cr_assert_stdout_eq_str("1E240");
}

Test (my_printf, b, .init = redirect_all_std)
{
    my_printf("%b", 123);
    cr_assert_stdout_eq_str("1111011");
}

Test (my_printf, o, .init = redirect_all_std)
{
    my_printf("%o", 123);
    cr_assert_stdout_eq_str("173");
}

Test (my_printf, O, .init = redirect_all_std)
{
    my_printf("%O", 123);
    cr_assert_stdout_eq_str("173");
}

Test (my_printf, u, .init = redirect_all_std)
{
    unsigned int ok = 12;
    my_printf("%u", ok);
    cr_assert_stdout_eq_str("12");
}

Test (my_printf, u2, .init = redirect_all_std)
{
    unsigned int ok = 0;
    my_printf("%u", ok);
    cr_assert_stdout_eq_str("0");
}

Test (my_printf, S_32, .init = redirect_all_std)
{
    my_printf("hello%S", "Salut\n");
    cr_assert_stdout_eq_str("helloSalut\\12");
}

Test (my_printf, other, .init = redirect_all_std)
{
    my_printf("hello%");
    cr_assert_stdout_eq_str("hello%");
}