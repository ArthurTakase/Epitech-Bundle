/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** AGame
*/

#ifndef AGAME_HPP_
#define AGAME_HPP_

#include "IGame.hpp"

class AGame : public virtual IGame {
protected:
    std::string       name;
    Arcade::GameState state;
    Arcade::Color     backgroundColor;
    int               score;
    std::string       music;

public:
    AGame(std::string name, Arcade::Color backgroundColor, std::string music);
    AGame(const AGame &other) = default;
    AGame(AGame &&other)      = default;
    ~AGame() noexcept         = default;
    AGame &operator=(const AGame &other) noexcept = default;
    AGame &operator=(AGame &&other) noexcept = default;

protected:
    std::string       getName() const noexcept final;
    Arcade::GameState getState() const noexcept final;
    Arcade::Color     getBackgroundColor() const noexcept final;
    int               getScore() const noexcept final;
    std::string       getMusic() const noexcept final;
};

#endif /* !AGAME_HPP_ */
