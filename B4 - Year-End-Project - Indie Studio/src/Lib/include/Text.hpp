/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Text
*/

#pragma once
#include <string>
#include <string_view>

#include "Color.hpp"
#include "Vector.hpp"
#include "raylib.h"

class TextHandler
{
  public:
    TextHandler(const std::string_view& font_path,
        const std::string_view&         message,
        int                             posX,
        int                             posY) noexcept;
    TextHandler(const TextHandler& other) noexcept = delete;
    TextHandler(TextHandler&& other) noexcept;
    ~TextHandler() noexcept;

    TextHandler& operator=(const TextHandler& rhs) noexcept = delete;
    TextHandler& operator                                   =(TextHandler&& rhs) noexcept;

    void         draw() const noexcept;
    void         setTextColor(const std::array<unsigned char, 3>& color) noexcept;
    void         setTextSize(int size) noexcept;
    void         setPosition(int posX, int posY) noexcept;
    void         setText(const std::string_view& message) noexcept;
    void         unload() noexcept;
    void         invertDisplay() noexcept;
    std::string& getText() noexcept;

  protected:
  private:
    unsigned int font_size_ = 30;
    Font         font_;
    std::string  message_;
    Vector2D     position_;
    ColorManager color_;
    bool         unloaded_  = false;
    bool         displayed_ = true;
};