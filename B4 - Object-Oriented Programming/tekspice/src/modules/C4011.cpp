/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** C4011
*/

#include "../../include/C4011.hpp"

C4011::C4011() : AComponent(&_nand_gate)
{
    for (int i = 0; i != 14; i++) pins[i] = NULL;
}

C4011::~C4011() {}

nts::Tristate C4011::compute(std::size_t pin)
{
    nts::Tristate newValue = nts::Tristate::UNDEFINED;

    static size_t lastPin = -1;
    if (lastPin == pin) { exit(84); }
    lastPin = pin;

    if (pin == 3 && pins[0] && pins[1]) { newValue = method(pins[0]->compute(pin), pins[1]->compute(pin)); }
    if (pin == 4 && pins[4] && pins[5]) { newValue = method(pins[4]->compute(pin), pins[5]->compute(pin)); }
    if (pin == 11 && pins[11] && pins[12]) { newValue = method(pins[11]->compute(pin), pins[12]->compute(pin)); }
    if (pin == 10 && pins[7] && pins[8]) { newValue = method(pins[7]->compute(pin), pins[8]->compute(pin)); }

    setValue(newValue);
    return newValue;
}

void C4011::dump() const noexcept
{
    std::cout << "4011 [" << printableType() << "]" << std::endl;
    for (int i = 0; i != 14; i++) {
        std::cout << "\tpin #" << (i + 1) << "\t>> ";
        std::cout << (pins[i] ? "linked" : "null") << std::endl;
    }
}

void C4011::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

void C4011::simulate(std::size_t tick)
{
    (void)tick;
}

nts::Type C4011::typeComponent() const noexcept
{
    return nts::Type::COMPONENT;
}