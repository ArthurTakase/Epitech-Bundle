/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Window.cpp
*/

#pragma once

#include <Lib/Sprite.hpp>
#include <Lib/Text.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <bitset>

/**
 * @brief This class is used to create a window.
 *
 */
class Window
{
  public:
    Window() noexcept;
    ~Window() noexcept                   = default;
    Window(const Window& other) noexcept = delete;
    Window(Window&& other) noexcept      = delete;

    Window& operator=(const Window& rhs) noexcept = delete;
    Window& operator=(Window&& rhs) noexcept      = delete;

    void open(int width, int height, const std::string& title) noexcept;
    void close() noexcept;
    void clear() noexcept;
    void refresh() noexcept;
    bool isOpen() const noexcept;
    int  getKeyPressed() noexcept;
    void draw(Sprite& sprite, int xtexture, int ytexture, int width, int height) noexcept;
    void draw(Text& text) noexcept;

  private:
    sf::RenderWindow              window_;
    static constexpr unsigned int FRAMERATE_LIMIT = 30;
};
