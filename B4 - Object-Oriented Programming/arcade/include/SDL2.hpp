/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-arthur.decaen
** File description:
** SDL2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "ILibrary.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cstdlib>

class SDL2 : public virtual ILibrary {
private:
    std::string   name;
    int           frameStart;
    int           FPS;
    int           frameTime;
    int           frameDelay;
    SDL_Window   *window;
    SDL_Renderer *renderer;
    TTF_Font     *font;
    std::string   currentMusic;

public:
    SDL2();
    ~SDL2() noexcept;

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
