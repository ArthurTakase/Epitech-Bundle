/*
** EPITECH PROJECT, 2021
** B-CPE-210-BDX-2-1-solostumper01-arthur.decaen
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "test.h"

Test(suite_name, len) {
    cr_assert(my_strlen("salut") == 5);
}

Test(suite_name, pustr) {
    cr_redirect_stdout();
    my_putstr("salut");
    cr_assert_stdout_eq_str("salut");
}

Test(suite_name, in1) {
    cr_assert(in('i', "oui") == 1);
}

Test(suite_name, in2) {
    cr_assert(in('z', "oui") == 0);
}

Test(suite_name, check1) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "bonjour";
    argv[2] = "bonjourrrr";
    cr_redirect_stdout();
    anagram(3, argv);
    cr_assert_stdout_eq_str("no anagrams.\n");
}

Test(suite_name, check2) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "bonjour";
    argv[2] = "bonjour";
    cr_redirect_stdout();
    anagram(3, argv);
    cr_assert_stdout_eq_str("anagram!\n");
}

Test(suite_name, check3) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "bonjour";
    argv[2] = "bonjoru";
    cr_redirect_stdout();
    anagram(3, argv);
    cr_assert_stdout_eq_str("anagram!\n");
}

Test(suite_name, check4) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "bonjour";
    argv[2] = "bonjorz";
    cr_redirect_stdout();
    anagram(3, argv);
    cr_assert_stdout_eq_str("no anagrams.\n");
}

Test(suite_name, return_main1) {
    char *argv[2];

    argv[0] = "toto";
    argv[1] = "bonjour";
    cr_assert(anagram(2, argv) == 84);
}

Test(suite_name, return_main2) {
    char *argv[3];

    argv[0] = "toto";
    argv[1] = "bonjour";
    argv[2] = "bonjour";
    cr_assert(anagram(3, argv) == 0);
}

Test(suite_name, return_main3) {
    char *argv[4];

    argv[0] = "toto";
    argv[1] = "bonjour";
    argv[2] = "toto";
    argv[3] = "bonjour";
    cr_assert(anagram(4, argv) == 84);
}