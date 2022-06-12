/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** SDL2
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "ILibrary.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

class SFML : public virtual ILibrary {
private:
    std::string                name;
    sf::RenderWindow           window;
    sf::Font                   font;
    std::string                currentMusic;
    std::unique_ptr<sf::Music> music;

public:
    SFML();
    ~SFML();

public:
    void        refreshLib() noexcept final;
    void        deleteWindow() noexcept final;
    void        putText(const Text &txt) noexcept final;
    void        clearLib(const Arcade::Color &color) noexcept final;
    void        putSprite(const Sprite &sprite) final;
    bool        createWindow() noexcept final;
    std::string getName() const noexcept final;
    Arcade::Key getInput() noexcept final;
    void        playSound(const std::string &sound) noexcept final;
    void        cleanSound() noexcept final;
};

extern "C" std::shared_ptr<ILibrary> createLib();

#endif
