/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL: Ubuntu-20.04]
** File description:
** AComponent
*/

#include "../include/AComponent.hpp"

AComponent::AComponent(nts::Tristate (*newMethod)(nts::Tristate var1, nts::Tristate var2))
{
    _value = nts::Tristate::UNDEFINED;
    method = newMethod;
}

AComponent::~AComponent() {}

bool AComponent::pinExist(std::size_t pin, std::size_t nb_pin_max) const noexcept
{
    return !(pin < 1 || pin > nb_pin_max);
}

nts::Tristate AComponent::getValue() const noexcept
{
    return _value;
}

void AComponent::setValue(nts::Tristate new_value) noexcept
{
    if (this->typeComponent() == nts::Type::CLOCK) { _isSwitchThisTurn = true; }
    _value = new_value;
}

std::string AComponent::printableType() const noexcept
{
    return ((getValue() == nts::Tristate::UNDEFINED) ? "U" : std::to_string((int)getValue()));
}