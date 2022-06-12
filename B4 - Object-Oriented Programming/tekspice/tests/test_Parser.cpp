/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/NanoTekSpice.hpp"
#include "../include/Parser.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(splitStr, succeed, .init=redirect_all_stdout)
{
    std::string test = "in:01";
    std::vector<std::string> res;
    std::vector<std::string> expected = {"in", "01"};

    splitStr(test, ":", &res);
    cr_expect_eq(res, expected);
}

Test(getDataFromFile, failedToOpen, .init=redirect_all_stdout)
{
    Parser parser;

    try {
        parser.getDataFromFile("none.txt");
    }
    catch(std::exception &e) {
        cr_expect_str_eq(e.what(), "Could not open none.txt");
    }
}