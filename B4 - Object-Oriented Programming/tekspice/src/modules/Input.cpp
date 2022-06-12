/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** Input
*/

#include "../../include/Input.hpp"

Input::Input() : AComponent(NULL)
{
    pins[0] = NULL;
    _type   = nts::Type::INPUT;
}

Input::Input(nts::Type type) : AComponent(NULL)
{
    pins[0] = NULL;
    _type   = type;
    if (_type == nts::Type::TRUE) { setValue(nts::Tristate::TRUE); }
    if (_type == nts::Type::FALSE) { setValue(nts::Tristate::FALSE); }
}

Input::~Input() {}

void Input::simulate(std::size_t tick)
{
    (void)tick;
    if (_type == nts::Type::CLOCK && !_isSwitchThisTurn) {
        if (_value == nts::Tristate::FALSE) _value = nts::Tristate::TRUE;
        else if (_value == nts::Tristate::TRUE)
            _value = nts::Tristate::FALSE;
    }
    _isSwitchThisTurn = false;
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
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

nts::Tristate Input::compute(std::size_t pin)
{
    if (!pinExist(pin, 15)) { throw ErrorPin(pin); }
    return getValue();
}

void Input::dump() const noexcept
{
    std::cout << "Input [" << printableType() << "]" << std::endl;
    std::cout << "\tpin #1\t>> " << (pins[0] ? "linked" : "null") << std::endl;
}

nts::Type Input::typeComponent() const noexcept
{
    return _type;
}