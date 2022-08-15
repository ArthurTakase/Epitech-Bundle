/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Color
*/

#pragma once
#include <array>

namespace Colors
{
static inline constexpr std::array<unsigned char, 3> C_WHITE      = { 255, 255, 255 };
static inline constexpr std::array<unsigned char, 3> C_LIGHTGRAY  = { 200, 200, 200 };
static inline constexpr std::array<unsigned char, 3> C_GRAY       = { 130, 130, 130 };
static inline constexpr std::array<unsigned char, 3> C_YELLOW     = { 253, 249, 0 };
static inline constexpr std::array<unsigned char, 3> C_GOLD       = { 255, 203, 0 };
static inline constexpr std::array<unsigned char, 3> C_ORANGE     = { 255, 161, 0 };
static inline constexpr std::array<unsigned char, 3> C_PINK       = { 255, 109, 194 };
static inline constexpr std::array<unsigned char, 3> C_RED        = { 230, 41, 55 };
static inline constexpr std::array<unsigned char, 3> C_MAROON     = { 190, 33, 55 };
static inline constexpr std::array<unsigned char, 3> C_GREEN      = { 0, 228, 48 };
static inline constexpr std::array<unsigned char, 3> C_LIME       = { 0, 158, 47 };
static inline constexpr std::array<unsigned char, 3> C_DARKGREEN  = { 0, 117, 44 };
static inline constexpr std::array<unsigned char, 3> C_SKYBLUE    = { 102, 191, 255 };
static inline constexpr std::array<unsigned char, 3> C_BLUE       = { 0, 121, 241 };
static inline constexpr std::array<unsigned char, 3> C_DARKBLUE   = { 0, 82, 172 };
static inline constexpr std::array<unsigned char, 3> C_PURPLE     = { 200, 122, 255 };
static inline constexpr std::array<unsigned char, 3> C_VIOLET     = { 135, 60, 190 };
static inline constexpr std::array<unsigned char, 3> C_DARKPURPLE = { 112, 31, 126 };
static inline constexpr std::array<unsigned char, 3> C_BEIGE      = { 211, 176, 131 };
static inline constexpr std::array<unsigned char, 3> C_BROWN      = { 127, 106, 79 };
static inline constexpr std::array<unsigned char, 3> C_DARKBROWN  = { 76, 63, 47 };
static inline constexpr std::array<unsigned char, 3> C_BLACK      = { 0, 0, 0 };
}

class ColorManager
{
  public:
    ColorManager(const std::array<unsigned char, 3>& color) noexcept;
    ColorManager(const ColorManager& other) noexcept = default;
    ColorManager(ColorManager&& other) noexcept      = default;
    ~ColorManager() noexcept                         = default;

    ColorManager& operator=(const ColorManager& rhs) noexcept = default;
    ColorManager& operator=(ColorManager&& rhs) noexcept = default;

    void                         setColor(const std::array<unsigned char, 3>& color) noexcept;
    std::array<unsigned char, 3> getColor() const noexcept;

  protected:
  private:
    std::array<unsigned char, 3> color_;
};