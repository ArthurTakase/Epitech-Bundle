/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** C4069
*/

#include "../../include/C4069.hpp"

C4069::C4069() : AComponent(&_reverse)
{
    for (int i = 0; i != 14; i++) pins[i] = NULL;
}

C4069::~C4069() {}

nts::Tristate C4069::compute(std::size_t pin)
{
    nts::Tristate newValue = nts::Tristate::UNDEFINED;

    static size_t lastPin = -1;
    if (lastPin == pin) { exit(84); }
    lastPin = pin;

    if (pin == 2 && pins[0]) { newValue = method(pins[0]->compute(pin), nts::Tristate::UNDEFINED); }
    if (pin == 4 && pins[2]) { newValue = method(pins[2]->compute(pin), nts::Tristate::UNDEFINED); }
    if (pin == 6 && pins[4]) { newValue = method(pins[4]->compute(pin), nts::Tristate::UNDEFINED); }
    if (pin == 12 && pins[12]) { newValue = method(pins[12]->compute(pin), nts::Tristate::UNDEFINED); }
    if (pin == 10 && pins[10]) { newValue = method(pins[10]->compute(pin), nts::Tristate::UNDEFINED); }
    if (pin == 8 && pins[8]) { newValue = method(pins[8]->compute(pin), nts::Tristate::UNDEFINED); }

    setValue(newValue);
    return newValue;
}

void C4069::dump() const noexcept
{
    std::cout << "4069 [" << printableType() << "]" << std::endl;
    for (int i = 0; i != 14; i++) {
        std::cout << "\tpin #" << (i + 1) << "\t>> ";
        std::cout << (pins[i] ? "linked" : "null") << std::endl;
    }
}

void C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (!pinExist(pin, 15)) { throw ErrorPin(pin); }
    if (pins[pin - 1] != NULL) { return; }

    pins[pin - 1] = &other;
    try {
        other.setLink(otherPin, *this, pin);
    }
    catch (ErrorPin &e) {
        throw e;
    }
}

void C4069::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Type C4069::typeComponent() const noexcept
{
    return nts::Type::COMPONENT;
}