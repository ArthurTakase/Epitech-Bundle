/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/C4030.hpp"
#include "../include/Input.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createC4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    cr_expect_neq(modXOr, NULL);
}

Test(dumpC4030, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    modXOr->dump();
    cr_expect_stdout_eq_str(
        "4030 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(getValueC4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    cr_expect_eq(modXOr->getValue(), nts::Tristate::UNDEFINED);
}

Test(computeC4030, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    cr_expect_eq(modXOr->compute(12), nts::Tristate::UNDEFINED);
}

Test(computePin3C4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    in1->setLink(1, *modXOr, 1);
    in2->setLink(1, *modXOr, 2);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modXOr->compute(3), nts::Tristate::FALSE);
}

Test(computePin4C4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    in1->setLink(1, *modXOr, 5);
    in2->setLink(1, *modXOr, 6);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modXOr->compute(4), nts::Tristate::TRUE);
}

Test(computePin10C4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    in1->setLink(1, *modXOr, 8);
    in2->setLink(1, *modXOr, 9);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modXOr->compute(10), nts::Tristate::FALSE);
}

Test(computePin11C4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    in1->setLink(1, *modXOr, 12);
    in2->setLink(1, *modXOr, 13);
    in1->setValue(nts::Tristate::FALSE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modXOr->compute(11), nts::Tristate::FALSE);
}

Test(setValueC4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modXOr(new C4030());

    cr_expect_eq(modXOr->getValue(), nts::Tristate::UNDEFINED);
    modXOr->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modXOr->getValue(), nts::Tristate::TRUE);
}

Test(simulateC4030, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNXor(new C4030());

    modNXor->simulate(2);
}

Test(setlinkC4030, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modXor(new C4030());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        modXor->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}