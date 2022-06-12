/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/C4011.hpp"
#include "../include/Input.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createC4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    cr_expect_neq(modNAnd, NULL);
}

Test(dumpC4011, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    modNAnd->dump();
    cr_expect_stdout_eq_str(
        "4011 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(getValueC4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    cr_expect_eq(modNAnd->getValue(), nts::Tristate::UNDEFINED);
}

Test(computeC4011, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    cr_expect_eq(modNAnd->compute(12), nts::Tristate::UNDEFINED);
}

Test(computePin3C4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    in1->setLink(1, *modNAnd, 1);
    in2->setLink(1, *modNAnd, 2);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modNAnd->compute(3), nts::Tristate::FALSE);
}

Test(computePin4C4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    in1->setLink(1, *modNAnd, 5);
    in2->setLink(1, *modNAnd, 6);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modNAnd->compute(4), nts::Tristate::TRUE);
}

Test(computePin10C4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    in1->setLink(1, *modNAnd, 8);
    in2->setLink(1, *modNAnd, 9);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modNAnd->compute(10), nts::Tristate::FALSE);
}

Test(computePin11C4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    in1->setLink(1, *modNAnd, 12);
    in2->setLink(1, *modNAnd, 13);
    in1->setValue(nts::Tristate::FALSE);
    in2->setValue(nts::Tristate::UNDEFINED);
    cr_expect_eq(modNAnd->compute(11), nts::Tristate::TRUE);
}

Test(setValueC4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNAnd(new C4011());

    cr_expect_eq(modNAnd->getValue(), nts::Tristate::UNDEFINED);
    modNAnd->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modNAnd->getValue(), nts::Tristate::TRUE);
}

Test(simulateC4011, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4011());

    modAnd->simulate(2);
}

Test(setlinkC4011, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4011());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        modAnd->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}