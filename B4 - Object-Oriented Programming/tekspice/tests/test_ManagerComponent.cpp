/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/ManagerComponent.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createC4001Manager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("4001");

    comp->dump();
    cr_expect_stdout_eq_str(
        "4001 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(createC4011Manager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("4011");

    comp->dump();
    cr_expect_stdout_eq_str(
        "4011 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(createC4030Manager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("4030");

    comp->dump();
    cr_expect_stdout_eq_str(
        "4030 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(createC4071Manager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("4071");

    comp->dump();
    cr_expect_stdout_eq_str(
        "4071 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(createC4069Manager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("4069");

    comp->dump();
    cr_expect_stdout_eq_str(
        "4069 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(createC4081Manager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("4081");

    comp->dump();
    cr_expect_stdout_eq_str(
        "4081 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(createInputManager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("input");

    comp->dump();
    cr_expect_stdout_eq_str("Input [U]\n\tpin #1\t>> null\n");
}

Test(createOutputManager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("output");

    comp->dump();
    cr_expect_stdout_eq_str("Output [U]\n\tpin #1\t>> null\n");
}

Test(createTrueManager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("true");

    comp->dump();
    cr_expect_stdout_eq_str("Input [1]\n\tpin #1\t>> null\n");
    cr_expect_eq(comp->typeComponent(), nts::Type::TRUE);
}

Test(createFalseManager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("false");

    comp->dump();
    cr_expect_stdout_eq_str("Input [0]\n\tpin #1\t>> null\n");
    cr_expect_eq(comp->typeComponent(), nts::Type::FALSE);
}

Test(createClockManager, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> comp = createComponent("clock");

    comp->dump();
    cr_expect_stdout_eq_str("Input [U]\n\tpin #1\t>> null\n");
    cr_expect_eq(comp->typeComponent(), nts::Type::CLOCK);
}

Test(createUnknown, failed, .init=redirect_all_stdout)
{
    try {
        std::unique_ptr<nts::IComponent> comp = createComponent("4000");
    }
    catch (ErrorComponent &e) {
        cr_expect_str_eq(e.what(), "Component, doesn't exist: 4000");
    }
}