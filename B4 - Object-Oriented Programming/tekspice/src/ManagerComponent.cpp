/*
** EPITECH PROJECT, 2022
** AComponentManagerComposent
** File description:
** AComponentManagerComponent
*/

#include "../include/ManagerComponent.hpp"

std::unique_ptr<nts::IComponent> create4001() noexcept
{
    return std::make_unique<C4001>();
}

std::unique_ptr<nts::IComponent> create4011() noexcept
{
    return std::make_unique<C4011>();
}

std::unique_ptr<nts::IComponent> create4030() noexcept
{
    return std::make_unique<C4030>();
}

std::unique_ptr<nts::IComponent> create4071() noexcept
{
    return std::make_unique<C4071>();
}

std::unique_ptr<nts::IComponent> create4081() noexcept
{
    return std::make_unique<C4081>();
}

std::unique_ptr<nts::IComponent> create4069() noexcept
{
    return std::make_unique<C4069>();
}

std::unique_ptr<nts::IComponent> input() noexcept
{
    return std::make_unique<Input>();
}

std::unique_ptr<nts::IComponent> output() noexcept
{
    return std::make_unique<Output>();
}

std::unique_ptr<nts::IComponent> makeTrue() noexcept
{
    return std::make_unique<Input>(nts::Type::TRUE);
}

std::unique_ptr<nts::IComponent> makeFalse() noexcept
{
    return std::make_unique<Input>(nts::Type::FALSE);
}

std::unique_ptr<nts::IComponent> makeClock() noexcept
{
    return std::make_unique<Input>(nts::Type::CLOCK);
}

std::unique_ptr<nts::IComponent> createComponent(const std::string &type)
{
    std::map<std::string, std::unique_ptr<nts::IComponent> (*)(void)> my_map = {
        { "4001", &create4001 }, { "4011", &create4011 }, { "4030", &create4030 }, { "4071", &create4071 },
        { "4081", &create4081 }, { "4069", &create4069 }, { "input", &input },     { "output", &output },
        { "true", &makeTrue },   { "false", &makeFalse }, { "clock", &makeClock }
    };

    if (!my_map[type]) throw ErrorComponent(type);
    return my_map[type]();
}