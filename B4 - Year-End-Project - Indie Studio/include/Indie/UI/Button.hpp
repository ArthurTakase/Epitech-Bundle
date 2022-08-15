/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Button
*/

#pragma once

#include <functional>
#include <string>

#include "Color.hpp"
#include "Mouse.hpp"
#include "Rectangle.hpp"
#include "Sound.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

class Button
{
  public:
    Button() noexcept = delete;
    Button(const std::string&     texture_path,
        float                     pos_x,
        float                     pos_y,
        std::function<void(void)> function,
        const std::string&        font_path,
        const std::string&        message,
        int                       textPosX,
        int                       textPosY) noexcept;
    Button(const std::string&     texture_path,
        float                     pos_x,
        float                     pos_y,
        std::function<void(void)> function,
        const std::string&        font_path,
        const std::string&        message,
        int                       textPosX,
        int                       textPosY,
        bool                      sound) noexcept;
    Button(const std::string&     texture_path,
        float                     pos_x,
        float                     pos_y,
        std::function<void(void)> function,
        const std::string&        font_path,
        const std::string&        message) noexcept;
    Button(const std::string&     texture_path,
        float                     pos_x,
        float                     pos_y,
        std::function<void(void)> function,
        const std::string&        font_path,
        const std::string&        message,
        float                     scale) noexcept;
    Button(const Button& other) noexcept = delete;
    Button(Button&& other) noexcept      = default;
    ~Button() noexcept                   = default;

    Button& operator=(const Button& rhs) noexcept = delete;
    Button& operator=(Button&& rhs) noexcept = default;

    void draw() const noexcept;
    void draw(float scale) const noexcept;
    void action() const noexcept;
    bool checkCollision(const MouseHandler& mouse_) noexcept;
    void setState(int state) noexcept;
    void setPosition(const Vector2& pos) noexcept;
    void setTextPosition(const Vector2& pos) noexcept;
    void setText(std::string new_text) noexcept;
    void invertDisplay() noexcept;
    void setTextSize(int size) noexcept;

  protected:
  private:
    SoundManager              fx_clicked_;
    SoundManager              fx_hover_;
    Sprite                    texture_;
    float                     scale_     = 1.0f;
    int                       state_     = 0;
    bool                      is_action_ = false;
    RectangleManager          rectangle_;
    std::function<void(void)> task_;
    TextHandler               text_;
    ColorManager              color_;
    bool                      sound = true;

    static const inline char* ON_CLICK = "assets/audios/OnClick.wav";
    static const inline char* ON_HOVER = "assets/audios/MenuHover.wav";
};
