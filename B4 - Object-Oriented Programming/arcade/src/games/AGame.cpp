/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** AGames
*/

#include "AGame.hpp"

AGame::AGame(std::string name, Arcade::Color backgroundColor, std::string music)
    : name(name), state(Arcade::GameState::PROGRESS), backgroundColor(backgroundColor), score(0), music(music)
{
}

std::string AGame::getName() const noexcept
{
    return name;
}

Arcade::GameState AGame::getState() const noexcept
{
    return state;
}

Arcade::Color AGame::getBackgroundColor() const noexcept
{
    return backgroundColor;
}

int AGame::getScore() const noexcept
{
    return score;
}

std::string AGame::getMusic() const noexcept
{
    return music;
}