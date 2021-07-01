/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-solostumper01-arthur.decaen
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"

Test(suite_name, main1) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "9";
    argv[2] = "18";
    cr_assert(fozzbazz(3, argv) == 0);
}

Test(suite_name, main2) {
    char *argv[1];

    argv[0] = "toto";
    cr_assert(fozzbazz(1, argv) == 84);
}

Test(suite_name, main3) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "2";
    argv[2] = "1";
    cr_assert(fozzbazz(3, argv) == 84);
}

Test(suite_name, main4) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "+";
    argv[2] = "1";
    cr_assert(fozzbazz(3, argv) == 84);
}

Test(suite_name, main5) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "1";
    argv[2] = "a";
    cr_assert(fozzbazz(3, argv) == 84);
}

Test(suite_name, main6) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = NULL;
    argv[2] = "a";
    cr_assert(fozzbazz(3, argv) == 84);
}

Test(suite_name, return_value1) {
    char *argv[3];
    char *result = "Bazz\nFozz\n11\nFozz\n13\nFozz\n15\nFozz\n17\nFozzBazz\n";

    argv[0] = "toto";
    argv[1] = "9";
    argv[2] = "18";
    printf("ceci permet de debug le test");
    cr_redirect_stdout();
    fozzbazz(3, argv);
    cr_assert_stdout_eq_str(result);
}