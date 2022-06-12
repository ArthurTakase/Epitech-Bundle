/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include "../include/C4001.hpp"
#include "../include/Input.hpp"
#include "../include/Output.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void);

Test(createOutput, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> output(new Output());

    cr_expect_neq(output, NULL);
}

Test(dumpOutput, set_to_null, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> output(new Output());

    output->dump();
    cr_expect_stdout_eq_str("Output [U]\n\tpin #1\t>> null\n");
}

Test(getValueOutput, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> output(new Output());

    cr_expect_eq(output->getValue(), nts::Tristate::UNDEFINED);
}

Test(computeOutput, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> output(new Output());

    try {
        output->compute(1);
    }
    catch (std::exception &e) {
        cr_expect_str_eq(e.what(), "Output not linked");
    }
}

Test(computePin11Output, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> in1(new Input());
    std::unique_ptr<nts::IComponent> in2(new Input());
    std::unique_ptr<nts::IComponent> modNor(new C4001());
    std::unique_ptr<nts::IComponent> output(new Output());

    in1->setLink(1, *modNor, 12);
    in2->setLink(1, *modNor, 13);
    modNor->setLink(11, *output, 1);
    in1->setValue(nts::Tristate::FALSE);
    in2->setValue(nts::Tristate::FALSE);
    cr_expect_eq(output->compute(1), nts::Tristate::TRUE);
}

Test(setValueOutput, succeed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> output(new Output());

    cr_expect_eq(output->getValue(), nts::Tristate::UNDEFINED);
    output->setValue(nts::Tristate::TRUE);
    cr_expect_eq(output->getValue(), nts::Tristate::TRUE);
}

Test(simulateOutput, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> output(new Output());

    try  {
        output->simulate(2);
    }
    catch (std::exception &e) {
        cr_expect_str_eq(e.what(), "std::exception");
    }
}

Test(setlinkOutput, failed, .init = redirect_all_stdout)
{
    std::unique_ptr<nts::IComponent> output(new Output());
    std::unique_ptr<nts::IComponent> in1(new Input());

    try {
        output->setLink(1, *in1, 0);
    }
    catch (const std::exception &e) {
        cr_expect_str_eq(e.what(), "Pin, doesn't exist: 0");
    }
}