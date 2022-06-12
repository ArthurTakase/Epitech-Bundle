/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** Element
*/

#ifndef ELEMENTS_HPP_
#define ELEMENTS_HPP_

#include "Misc.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Sprite {
public:
    Sprite();
    Sprite(std::string filePath, Arcade::Color color, size_t x, size_t y);
    Sprite(const Sprite &other);
    Sprite(const Sprite &&other);
    ~Sprite() noexcept = default;

    Sprite &operator=(const Sprite &other) noexcept;
    Sprite &operator=(Sprite &&other) noexcept;

public:
    std::string   spritePath;
    Arcade::Color color;
    int           x;
    int           y;
};

class Text {
public:
    Text(std::string str, Arcade::TextColor color, size_t x, size_t y, bool underline);
    Text(const Text &other);
    Text(const Text &&other);
    ~Text() noexcept = default;

    Text &operator=(const Text &other) noexcept;
    Text &operator=(Text &&other) noexcept;

public:
    std::string       str;
    Arcade::TextColor color;
    size_t            x;
    size_t            y;
    bool              underline;
};

#endif /* !ELEMENTS_HPP_ */
