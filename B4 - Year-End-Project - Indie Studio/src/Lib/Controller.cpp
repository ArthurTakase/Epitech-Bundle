/*
** EPITECH PROJECT, 2022
** B-YEP-400-BDX-4-1-indiestudio-arthur.decaen
** File description:
** Controller
*/

#include "Controller.hpp"

/**
 * It returns true if the specified key is currently pressed down
 *
 * @param key The key to check.
 *
 * @return A boolean value.
 */
bool Controller::isKeyDown(const Key& key) const noexcept
{
    return IsKeyDown(static_cast<KeyboardKey>(key));
}

/**
 * If the key is pressed, return true, otherwise return false
 *
 * @param key The key to check.
 *
 * @return A boolean value.
 */
bool Controller::isKeyPressed(const Key& key) const noexcept
{
    return IsKeyPressed(static_cast<KeyboardKey>(key));
}

/**
 * It returns true if the gamepad is connected, false otherwise
 *
 * @param id The ID of the gamepad to check.
 *
 * @return A boolean value.
 */
bool Controller::isGamepadConnected(int id) const noexcept
{
    return IsGamepadAvailable(id);
}

/**
 * It returns true if the specified gamepad button is pressed
 *
 * @param id The id of the gamepad to check.
 * @param button The button to check.
 *
 * @return A boolean value.
 */
bool Controller::isGamepadButtonPressed(int id, const G_Button& button) const noexcept
{
    return IsGamepadButtonPressed(id, static_cast<GamepadButton>(button));
}

/**
 * It returns the value of the specified axis of the specified gamepad
 *
 * @param id The ID of the gamepad to check.
 * @param axis The axis to check.
 *
 * @return The value of the axis.
 */
float Controller::getGamepadAxis(int id, const Axis& axis) const noexcept
{
    return GetGamepadAxisMovement(id, static_cast<GamepadAxis>(axis));
}