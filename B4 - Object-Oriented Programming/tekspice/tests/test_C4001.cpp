/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/C4001.hpp"
#include "../include/Input.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createC4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    cr_expect_neq(modNor, NULL);
}

Test(dumpC4001, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    modNor->dump();
    cr_expect_stdout_eq_str(
        "4001 [U]\n\tpin #1\t>> null\n\tpin #2\t>> null\n\tpin #3\t>> null\n\tpin #4\t>> null\n\tpin #5\t>> "
        "null\n\tpin #6\t>> null\n\tpin #7\t>> null\n\tpin #8\t>> null\n\tpin #9\t>> null\n\tpin #10\t>> null\n\tpin "
        "#11\t>> null\n\tpin #12\t>> null\n\tpin #13\t>> null\n\tpin #14\t>> null\n");
}

Test(getValueC4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    cr_expect_eq(modNor->getValue(), nts::Tristate::UNDEFINED);
}

Test(computeC4001, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    cr_expect_eq(modNor->compute(12), nts::Tristate::UNDEFINED);
}

Test(computePin3C4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    in1->setLink(1, *modNor, 1);
    in2->setLink(1, *modNor, 2);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modNor->compute(3), nts::Tristate::FALSE);
}

Test(computePin4C4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    in1->setLink(1, *modNor, 5);
    in2->setLink(1, *modNor, 6);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modNor->compute(4), nts::Tristate::FALSE);
}

Test(computePin10C4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    in1->setLink(1, *modNor, 8);
    in2->setLink(1, *modNor, 9);
    in1->setValue(nts::Tristate::TRUE);
    in2->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modNor->compute(10), nts::Tristate::FALSE);
}

Test(computePin11C4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    in1->setLink(1, *modNor, 12);
    in2->setLink(1, *modNor, 13);
    in1->setValue(nts::Tristate::FALSE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(modNor->compute(11), nts::Tristate::TRUE);
}

Test(setValueC4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    cr_expect_eq(modNor->getValue(), nts::Tristate::UNDEFINED);
    modNor->setValue(nts::Tristate::TRUE);
    cr_expect_eq(modNor->getValue(), nts::Tristate::TRUE);
}

Test(simulateC4001, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNor(new C4001());

    modNor->simulate(2);
}

Test(setlinkC4001, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> modNor(new C4001());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        modNor->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}