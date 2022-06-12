/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL: Ubuntu-20.04]
** File description:
** Methods
*/

#include "../include/IComponent.hpp"

nts::Tristate _reverse(nts::Tristate input, nts::Tristate none) noexcept
{
    (void)none;

    switch (input) {
    case nts::Tristate::TRUE: return nts::Tristate::FALSE;
    case nts::Tristate::FALSE: return nts::Tristate::TRUE;
    default: return nts::Tristate::UNDEFINED;
    }
}

nts::Tristate _or_gate(nts::Tristate input1, nts::Tristate input2) noexcept
{
    if (input1 == nts::Tristate::TRUE or input2 == nts::Tristate::TRUE) return nts::Tristate::TRUE;
    if (input1 == nts::Tristate::UNDEFINED || input2 == nts::Tristate::UNDEFINED) return nts::Tristate::UNDEFINED;
    return nts::Tristate::FALSE;
}

nts::Tristate _nor_gate(nts::Tristate input1, nts::Tristate input2) noexcept
{
    return _reverse(_or_gate(input1, input2), nts::Tristate::UNDEFINED);
}

nts::Tristate _xor_gate(nts::Tristate input1, nts::Tristate input2) noexcept
{
    if (input1 == nts::Tristate::UNDEFINED || input2 == nts::Tristate::UNDEFINED) return nts::Tristate::UNDEFINED;
    if (input1 != input2) return nts::Tristate::TRUE;
    return nts::Tristate::FALSE;
}

nts::Tristate _and_gate(nts::Tristate input1, nts::Tristate input2) noexcept
{

    if (input1 == nts::Tristate::FALSE || input2 == nts::Tristate::FALSE) return nts::Tristate::FALSE;
    if (input1 == nts::Tristate::UNDEFINED || input2 == nts::Tristate::UNDEFINED) return nts::Tristate::UNDEFINED;
    return nts::Tristate::TRUE;
}

nts::Tristate _nand_gate(nts::Tristate input1, nts::Tristate input2) noexcept
{
    return _reverse(_and_gate(input1, input2), nts::Tristate::UNDEFINED);
}