/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Window.cpp
*/

#include <Lib/Window.hpp>
#include <Tools/Keyboard.hpp>
#include <iostream>

Window::Window() noexcept {}

/**
 * It opens the window
 */
void Window::open(int width, int height, const std::string& title) noexcept
{
    unsigned int w = static_cast<unsigned int>(width);
    unsigned int h = static_cast<unsigned int>(height);

    sf::VideoMode mode({w, h});
    window_.create(mode, title);
    window_.setFramerateLimit(FRAMERATE_LIMIT);
}

/**
 * It closes the window
 */
void Window::close() noexcept
{
    window_.close();
}

/**
 * It clears the window_
 */
void Window::clear() noexcept
{
    window_.clear();
}

/**
 * It refreshes the window_
 */
void Window::refresh() noexcept
{
    window_.display();
}

/**
 * Returns true if the window_ is open, false otherwise.
 *
 * @return A boolean value.
 */
bool Window::isOpen() const noexcept
{
    return window_.isOpen();
}

/**
 * If the window_ is closed, return 255. If a key is pressed, return the key code. Otherwise, return 0
 *
 * @return A bitset of 8 bits.
 */
int Window::getKeyPressed() noexcept
{
    sf::Event event;

    if (!window_.pollEvent(event)) return Input::None;
    if (event.type == sf::Event::Closed) return Input::Exit;
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Left: return Input::Left;
            case sf::Keyboard::Right: return Input::Right;
            case sf::Keyboard::Up: return Input::Up;
            case sf::Keyboard::Down: return Input::Down;
            case sf::Keyboard::Space: return Input::Space;
            case sf::Keyboard::LShift: return Input::Shift;
            case sf::Keyboard::Z:
            case sf::Keyboard::W: return Input::Z;
            case sf::Keyboard::Q:
            case sf::Keyboard::A: return Input::Q;
            case sf::Keyboard::S: return Input::S;
            case sf::Keyboard::D: return Input::D;
            case sf::Keyboard::Escape: return Input::Exit;
            case sf::Keyboard::Enter: return Input::Return;
            case sf::Keyboard::Backspace: return Input::BackSpace;
            case sf::Keyboard::Num0:
            case sf::Keyboard::Numpad0: return Input::Zero;
            case sf::Keyboard::Num1:
            case sf::Keyboard::Numpad1: return Input::One;
            case sf::Keyboard::Num2:
            case sf::Keyboard::Numpad2: return Input::Two;
            case sf::Keyboard::Num3:
            case sf::Keyboard::Numpad3: return Input::Three;
            case sf::Keyboard::Num4:
            case 51:
            case sf::Keyboard::Numpad4: return Input::Four;
            case sf::Keyboard::Num5:
            case sf::Keyboard::Numpad5: return Input::Five;
            case sf::Keyboard::Num6:
            case 56:
            case sf::Keyboard::Numpad6: return Input::Six;
            case sf::Keyboard::Num7:
            case sf::Keyboard::Numpad7: return Input::Seven;
            case sf::Keyboard::Num8:
            case sf::Keyboard::Numpad8: return Input::Eight;
            case sf::Keyboard::Num9:
            case sf::Keyboard::Numpad9: return Input::Nine;
            case sf::Keyboard::Period:
            case sf::Keyboard::Comma:
            case sf::Keyboard::Slash:
            case sf::Keyboard::Semicolon:
            case -1: return Input::Dot;
            case sf::Keyboard::L: return Input::L;
            default: return Input::None;
        }
    }

    return Input::None;
}

/**
 * It draws a sprite on the window_
 *
 * @param sprite The sprite to draw.
 */
void Window::draw(Sprite& sprite, int xtexture, int ytexture, int width, int height) noexcept
{
    sprite.setTextureRect(xtexture, ytexture, width, height);

    sf::Sprite* tempSprite = static_cast<sf::Sprite*>(sprite.getSprite());

    window_.draw(*tempSprite);
}

/**
 * It draws a text on the window_
 *
 * @param text The text to draw.
 */
void Window::draw(Text& text) noexcept
{
    sf::Text* tempText = static_cast<sf::Text*>(text.getText());

    window_.draw(*tempText);
}