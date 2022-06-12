/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** SDL2
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "ILibrary.hpp"
#include <ncurses.h>

class Ncurses : public virtual ILibrary {
private:
    std::string name;
    WINDOW     *window;
    std::string currentMusic;

public:
    Ncurses();
    ~Ncurses() noexcept;

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
