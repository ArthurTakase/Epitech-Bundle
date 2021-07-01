/*
** EPITECH PROJECT, 2021
** Redirect all std
** File description:
** redirect_all_std
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stderr();
    cr_redirect_stdout();
}
