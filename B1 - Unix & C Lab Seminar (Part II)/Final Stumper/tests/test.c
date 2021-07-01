/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "include/my.h"
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(ok, test1)
{
    cr_assert_str_eq("[rush1-2] 1 1", "[rush1-2] 1 1");
}

Test(ok, test2)
{
    cr_assert_str_eq("[rush1-1] 12 12", "[rush1-1] 12 12");
}

Test(ok, test3)
{
    cr_assert_str_eq("[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1",
                     "[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1");
}
