/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-solostumper01-arthur.decaen
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

int main_function(int argc, char *argv);

Test(suite_name, abc) {
    cr_redirect_stdout();
    main_function(2, "Salut les cocos");
    cr_assert_stdout_eq_str("Salut les cocos\n");
}

Test(suite_name, Rome) {
    cr_redirect_stdout();
    main_function(2, " Remus and Romulus are the two mammals of Rome ");
    cr_assert_stdout_eq_str("Remus and Romulus are the two mammals of Rome\n");
}

Test(suite_name, echo) {
    cr_redirect_stdout();
    main_function(2, "\tHello\t\t how are you?\t ");
    cr_assert_stdout_eq_str("Hello how are you?\n");
}

Test(suite_name, echo2) {
    cr_redirect_stdout();
    main_function(2, " \tHello\t\t how are you?\t ");
    cr_assert_stdout_eq_str("Hello how are you?\n");
}

Test(suite_name, no_argument) {
    cr_assert(main_function(1, "") == 0);
}