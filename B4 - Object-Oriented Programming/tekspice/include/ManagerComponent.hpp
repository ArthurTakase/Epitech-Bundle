/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL: Ubuntu-20.04]
** File description:
** ManagerComponent
*/

#include "C4001.hpp"
#include "C4011.hpp"
#include "C4030.hpp"
#include "C4071.hpp"
#include "C4081.hpp"
#include "C4069.hpp"
#include "ErrorComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include <map>

#ifndef MANAGERCOMPONENT_HPP_
#define MANAGERCOMPONENT_HPP_

std::unique_ptr<nts::IComponent> create4001() noexcept;
std::unique_ptr<nts::IComponent> create4011() noexcept;
std::unique_ptr<nts::IComponent> create4030() noexcept;
std::unique_ptr<nts::IComponent> create4071() noexcept;
std::unique_ptr<nts::IComponent> create4081() noexcept;
std::unique_ptr<nts::IComponent> create4069() noexcept;
std::unique_ptr<nts::IComponent> input() noexcept;
std::unique_ptr<nts::IComponent> output() noexcept;
std::unique_ptr<nts::IComponent> makeTrue() noexcept;
std::unique_ptr<nts::IComponent> makeFalse() noexcept;
std::unique_ptr<nts::IComponent> makeClock() noexcept;
std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

#endif /* !MANAGERCOMPONENT_HPP_ */
