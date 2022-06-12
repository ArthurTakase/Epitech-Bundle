/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/C4071.hpp"
#include "../include/Input.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createC4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    cr_expect_neq(modOr, NULL);
}

Test(dumpC4071, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    modOr->dump();
    cr_expect_stdout_eq_str(
        "4071 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(getValueC4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    cr_expect_eq(modOr->getValue(), nts::Tristate::UNDEFINED);
}

Test(computeC4071, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    cr_expect_eq(modOr->compute(12), nts::Tristate::UNDEFINED);
}

Test(computePin3C4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    in1->setLink(1, *modOr, 1);
    in2->setLink(1, *modOr, 2);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modOr->compute(3), nts::Tristate::TRUE);
}

Test(computePin4C4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    in1->setLink(1, *modOr, 5);
    in2->setLink(1, *modOr, 6);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modOr->compute(4), nts::Tristate::TRUE);
}

Test(computePin10C4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    in1->setLink(1, *modOr, 8);
    in2->setLink(1, *modOr, 9);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modOr->compute(10), nts::Tristate::TRUE);
}

Test(computePin11C4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    in1->setLink(1, *modOr, 12);
    in2->setLink(1, *modOr, 13);
    in1->setValue(nts::Tristate::FALSE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modOr->compute(11), nts::Tristate::FALSE);
}

Test(setValueC4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    cr_expect_eq(modOr->getValue(), nts::Tristate::UNDEFINED);
    modOr->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modOr->getValue(), nts::Tristate::TRUE);
}

Test(simulateC4071, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modOr(new C4071());

    modOr->simulate(2);
}

Test(setlinkC4071, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modor(new C4071());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        modor->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}