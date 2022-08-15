/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** main
*/

#include <iostream>
#include <memory>

#include "Core.hpp"
#include "Error.hpp"
#include "Window.hpp"

int main()
{
    try {
        srand(time(NULL));
        auto core = std::make_unique<Core>();
        core->run();
    } catch (const Error& error) {
        std::cerr << error.what() << std::endl;
        return (
            static_cast<typename std::underlying_type<ReturnCode>::type>(ReturnCode::ERROR_CODE));
    }
    return (static_cast<typename std::underlying_type<ReturnCode>::type>(ReturnCode::SUCCESS_CODE));
}
