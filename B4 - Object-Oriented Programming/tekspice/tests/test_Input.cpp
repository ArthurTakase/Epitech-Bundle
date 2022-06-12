/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/Input.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createInput, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> input(new Input());

    cr_expect_neq(input, NULL);
}

Test(dumpInput, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> input(new Input());

    input->dump();
    cr_expect_stdout_eq_str("Input [U]\n\tpin #1\t>> null\n");
}

Test(getValueInput, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> input(new Input());

    cr_expect_eq(input->getValue(), nts::Tristate::UNDEFINED);
}

Test(computInput, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> input(new Input());

    cr_expect_eq(input->compute(1), nts::Tristate::UNDEFINED);
}

Test(simulateInput, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> input(new Input());

    try  {
        input->simulate(2);
    }
    catch (std::exception &e) {
        cr_expect_str_eq(e.what(), "std::exception");
    }
}

Test(setlinkInput, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> input(new Input());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        input->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}

Test(simulateClock, succeed, .init=redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> clock(new Input(nts::Type::CLOCK));

    clock->setValue(nts::Tristate::TRUE);
    cr_expect_eq(clock->typeComponent(), nts::Type::CLOCK);
    cr_expect_eq(clock->getValue(), nts::Tristate::TRUE);
    clock->simulate(1);
    clock->simulate(1);
    cr_expect_eq(clock->getValue(), nts::Tristate::FALSE);
}