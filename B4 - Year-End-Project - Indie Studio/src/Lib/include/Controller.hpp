/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** Controller.cpp
*/

#pragma once
#include "raylib.h"

enum class Key {
    K_NULL          = 0,
    K_APOSTROPHE    = 39,
    K_COMMA         = 44,
    K_MINUS         = 45,
    K_PERIOD        = 46,
    K_SLASH         = 47,
    K_ZERO          = 48,
    K_ONE           = 49,
    K_TWO           = 50,
    K_THREE         = 51,
    K_FOUR          = 52,
    K_FIVE          = 53,
    K_SIX           = 54,
    K_SEVEN         = 55,
    K_EIGHT         = 56,
    K_NINE          = 57,
    K_SEMICOLON     = 59,
    K_EQUAL         = 61,
    K_A             = 65,
    K_B             = 66,
    K_C             = 67,
    K_D             = 68,
    K_E             = 69,
    K_F             = 70,
    K_G             = 71,
    K_H             = 72,
    K_I             = 73,
    K_J             = 74,
    K_K             = 75,
    K_L             = 76,
    K_M             = 77,
    K_N             = 78,
    K_O             = 79,
    K_P             = 80,
    K_Q             = 81,
    K_R             = 82,
    K_S             = 83,
    K_T             = 84,
    K_U             = 85,
    K_V             = 86,
    K_W             = 87,
    K_X             = 88,
    K_Y             = 89,
    K_Z             = 90,
    K_LEFT_BRACKET  = 91,
    K_BACKSLASH     = 92,
    K_RIGHT_BRACKET = 93,
    K_GRAVE         = 96,
    K_SPACE         = 32,
    K_ESCAPE        = 256,
    K_ENTER         = 257,
    K_TAB           = 258,
    K_BACKSPACE     = 259,
    K_INSERT        = 260,
    K_DELETE        = 261,
    K_RIGHT         = 262,
    K_LEFT          = 263,
    K_DOWN          = 264,
    K_UP            = 265,
    K_PAGE_UP       = 266,
    K_PAGE_DOWN     = 267,
    K_HOME          = 268,
    K_END           = 269,
    K_CAPS_LOCK     = 280,
    K_SCROLL_LOCK   = 281,
    K_NUM_LOCK      = 282,
    K_PRINT_SCREEN  = 283,
    K_PAUSE         = 284,
    K_F1            = 290,
    K_F2            = 291,
    K_F3            = 292,
    K_F4            = 293,
    K_F5            = 294,
    K_F6            = 295,
    K_F7            = 296,
    K_F8            = 297,
    K_F9            = 298,
    K_F10           = 299,
    K_F11           = 300,
    K_F12           = 301,
    K_LEFT_SHIFT    = 340,
    K_LEFT_CONTROL  = 341,
    K_LEFT_ALT      = 342,
    K_LEFT_SUPER    = 343,
    K_RIGHT_SHIFT   = 344,
    K_RIGHT_CONTROL = 345,
    K_RIGHT_ALT     = 346,
    K_RIGHT_SUPER   = 347,
    K_KB_MENU       = 348,
    K_KP_0          = 320,
    K_KP_1          = 321,
    K_KP_2          = 322,
    K_KP_3          = 323,
    K_KP_4          = 324,
    K_KP_5          = 325,
    K_KP_6          = 326,
    K_KP_7          = 327,
    K_KP_8          = 328,
    K_KP_9          = 329,
    K_KP_DECIMAL    = 330,
    K_KP_DIVIDE     = 331,
    K_KP_MULTIPLY   = 332,
    K_KP_SUBTRACT   = 333,
    K_KP_ADD        = 334,
    K_KP_ENTER      = 335,
    K_KP_EQUAL      = 336,
    K_BACK          = 4,
    K_MENU          = 82,
    K_VOLUME_UP     = 24,
    KEY_VOLUME_DOWN = 25
};

enum class Axis {
    G_AXIS_LEFT_X        = 0,
    G_AXIS_LEFT_Y        = 1,
    G_AXIS_RIGHT_X       = 2,
    G_AXIS_RIGHT_Y       = 3,
    G_AXIS_LEFT_TRIGGER  = 4,
    G_AXIS_RIGHT_TRIGGER = 5
};

enum class G_Button {
    G_UNKNOWN = 0,
    G_DPAD_UP,
    G_DPAD_RIGHT,
    G_DPAD_DOWN,
    G_DPAD_LEFT,
    G_Y,
    G_B,
    G_A,
    G_X,
    G_LEFT_TRIGGER_1,
    G_LEFT_TRIGGER_2,
    G_RIGHT_TRIGGER_1,
    G_RIGHT_TRIGGER_2,
    G_SELECT,
    G_HOME,
    G_START,
    G_LEFT_THUMB,
    G_BUTTON
};

class Controller
{
  public:
    Controller() noexcept                        = default;
    ~Controller() noexcept                       = default;
    Controller(const Controller& other) noexcept = default;
    Controller(Controller&& other) noexcept      = default;

    Controller& operator=(const Controller& rhs) noexcept = default;
    Controller& operator=(Controller&& rhs) noexcept = default;

    bool  isKeyDown(const Key& key) const noexcept;
    bool  isKeyPressed(const Key& key) const noexcept;
    bool  isGamepadConnected(int id) const noexcept;
    bool  isGamepadButtonPressed(int id, const G_Button& button) const noexcept;
    float getGamepadAxis(int id, const Axis& axis) const noexcept;
};