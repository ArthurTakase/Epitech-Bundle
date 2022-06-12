/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** Output
*/

#include "../../include/Output.hpp"

Output::Output() : AComponent(NULL)
{
    pins[0] = NULL;
}

Output::~Output() {}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (!pinExist(pin, 15)) { throw ErrorPin(pin); }
    if (pins[pin - 1] != NULL) { return; }

    _otherPin     = otherPin;
    pins[pin - 1] = &other;
    try {
        other.setLink(otherPin, *this, pin);
    }
    catch (ErrorPin &e) {
        throw e;
    }
}

nts::Tristate Output::compute(std::size_t pin)
{
    if (pins[pin] == NULL) { throw ErrorLink(); }
    if (pin > 1) { throw ErrorPin(pin); }
    if (!pinExist(pin, 15)) { throw ErrorPin(pin); }
    if (!pins[pin - 1]) { return nts::Tristate::UNDEFINED; }

    setValue(pins[pin - 1]->compute(_otherPin));
    return getValue();
}

void Output::dump() const noexcept
{
    std::cout << "Output [" << printableType() << "]" << std::endl;
    std::cout << "\tpin #1\t>> " << (pins[0] ? "linked" : "null") << std::endl;
}

void Output::simulate(std::size_t tick)
{
    (void)tick;
    try {
        compute(1);
    }
    catch (std::exception &e) {
        throw e;
    }
}

nts::Type Output::typeComponent() const noexcept
{
    return nts::Type::OUTPUT;
}