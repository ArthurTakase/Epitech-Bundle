/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL: Ubuntu-20.04]
** File description:
** Gates
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "IComponent.hpp"

nts::Tristate _or_gate(nts::Tristate input1, nts::Tristate input2) noexcept;
nts::Tristate _nor_gate(nts::Tristate input1, nts::Tristate input2) noexcept;
nts::Tristate _xor_gate(nts::Tristate input1, nts::Tristate input2) noexcept;
nts::Tristate _and_gate(nts::Tristate input1, nts::Tristate input2) noexcept;
nts::Tristate _nand_gate(nts::Tristate input1, nts::Tristate input2) noexcept;
nts::Tristate _reverse(nts::Tristate input, nts::Tristate input2) noexcept;

#endif /* !GATES_HPP_ */
