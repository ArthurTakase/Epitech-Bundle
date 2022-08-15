/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Sprite.cpp
*/

#pragma once

#include <string_view>

#include "Color.hpp"
#include "raylib.h"

enum class SpriteType { S_WHITE, S_RED, S_BLUE, S_BLACK, S_NONE };

class Sprite
{
  public:
    Sprite(const std::string_view& path) noexcept;
    Sprite(const std::string_view& path, float x, float y) noexcept;
    Sprite(const std::string_view& path, float x, float y, float scale) noexcept;
    Sprite(const std::string_view& path, float x, float y, float scale, bool display) noexcept;

    Sprite(const Sprite& other) noexcept = default;
    Sprite(Sprite&& other) noexcept;
    ~Sprite() noexcept;

    Sprite& operator=(const Sprite& rhs) noexcept = default;
    Sprite& operator                              =(Sprite&& rhs) noexcept;

    void draw() const noexcept;
    void draw(const std::array<unsigned char, 3>& color) const noexcept;
    void draw(const std::array<unsigned char, 4>& color) const noexcept;

    int   getPosX() const noexcept;
    int   getPosY() const noexcept;
    float getWidth() const noexcept;
    float getHeight() const noexcept;
    void  setPos(float x, float y) noexcept;
    void  setScale(float scale) noexcept;
    bool  getDisplay() const noexcept;
    void  invertDisplay() noexcept;
    void  unload() noexcept;
    void  setDisplay(bool value) noexcept;

  protected:
  private:
    Image     image_;
    Texture2D texture_;
    float     pos_x_;
    float     pos_y_;
    float     scale_;
    bool      displayed_ = true;
    bool      unloaded_  = false;
};