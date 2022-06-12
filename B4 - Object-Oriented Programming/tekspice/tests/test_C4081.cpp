/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/C4081.hpp"
#include "../include/Input.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(createC4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    cr_expect_neq(modAnd, NULL);
}

Test(dumpC4081, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    modAnd->dump();
    cr_expect_stdout_eq_str(
        "4081 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(getValueC4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    cr_expect_eq(modAnd->getValue(), nts::Tristate::UNDEFINED);
}
Test(computeC4081, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    cr_expect_eq(modAnd->compute(12), nts::Tristate::UNDEFINED);
}

Test(computePin3C4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    in1->setLink(1, *modAnd, 1);
    in2->setLink(1, *modAnd, 2);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modAnd->compute(3), nts::Tristate::TRUE);
}

Test(computePin4C4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    in1->setLink(1, *modAnd, 5);
    in2->setLink(1, *modAnd, 6);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modAnd->compute(4), nts::Tristate::FALSE);
}

Test(computePin10C4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    in1->setLink(1, *modAnd, 8);
    in2->setLink(1, *modAnd, 9);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modAnd->compute(10), nts::Tristate::TRUE);
}

Test(computePin11C4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    in1->setLink(1, *modAnd, 12);
    in2->setLink(1, *modAnd, 13);
    in1->setValue(nts::Tristate::FALSE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modAnd->compute(11), nts::Tristate::FALSE);
}

Test(setValueC4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    cr_expect_eq(modAnd->getValue(), nts::Tristate::UNDEFINED);
    modAnd->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modAnd->getValue(), nts::Tristate::TRUE);
}

Test(simulateC4081, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4081());

    modAnd->simulate(2);
}

Test(setlinkC4081, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modAnd(new C4081());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        modAnd->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}