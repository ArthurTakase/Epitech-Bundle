/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/C4069.hpp"
#include "../include/Input.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createC4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> Not(new C4069());

    cr_expect_neq(Not, NULL);
}

Test(dumpC4069, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> Not(new C4069());

    Not->dump();
    cr_expect_stdout_eq_str(
        "4069 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(getValueC4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> Not(new C4069());

    cr_expect_eq(Not->getValue(), nts::Tristate::UNDEFINED);
}
Test(computeC4069, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> Not(new C4069());

    cr_expect_eq(Not->compute(12), nts::Tristate::UNDEFINED);
}

Test(computePin2C4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> Not(new C4069());

    in1->setLink(1, *Not, 1);
    in1->setValue(nts::Tristate::TRUE);
    cr_expect_eq(Not->compute(2), nts::Tristate::FALSE);
}

Test(computePin4C4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> Not(new C4069());

    in1->setLink(1, *Not, 3);
    in1->setValue(nts::Tristate::TRUE);
    cr_expect_eq(Not->compute(4), nts::Tristate::FALSE);
}

Test(computePin6C4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> Not(new C4069());

    in1->setLink(1, *Not, 5);
    in1->setValue(nts::Tristate::FALSE);
    cr_expect_eq(Not->compute(6), nts::Tristate::TRUE);
}

Test(computePin10C4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> Not(new C4069());

    in1->setLink(1, *Not, 11);
    in1->setValue(nts::Tristate::FALSE);
    cr_expect_eq(Not->compute(10), nts::Tristate::TRUE);
}

Test(computePin8C4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> Not(new C4069());

    in1->setLink(1, *Not, 9);
    in1->setValue(nts::Tristate::UNDEFINED);
    cr_expect_eq(Not->compute(8), nts::Tristate::UNDEFINED);
}

Test(computePin12C4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> Not(new C4069());

    in1->setLink(1, *Not, 13);
    in1->setValue(nts::Tristate::FALSE);
    cr_expect_eq(Not->compute(12), nts::Tristate::TRUE);
}

Test(setValueC4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> Not(new C4069());

    cr_expect_eq(Not->getValue(), nts::Tristate::UNDEFINED);
    Not->setValue(nts::Tristate::TRUE);
    cr_expect_eq(Not->getValue(), nts::Tristate::TRUE);
}

Test(simulateC4069, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> Not(new C4069());

    Not->simulate(2);
}

Test(setlinkC4069, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> Not(new C4069());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        Not->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}