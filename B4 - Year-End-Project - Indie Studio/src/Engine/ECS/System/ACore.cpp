/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** ICore
*/

#include "ACore.hpp"

/**
 * It returns a reference to the current scene
 *
 * @return A reference to the current scene.
 */
Scene& ACore::findScene() noexcept
{
    return (*scenes[data_.getCurrentSceneIndex()]);
}

/**
 * It returns a reference to the GameData object
 *
 * @return A reference to the data_ member.
 */
GameData& ACore::getData() noexcept
{
    return (data_);
}

/**
 * It returns a constant reference to the GameData object
 *
 * @return A reference to the data_ member.
 */
const GameData& ACore::getData() const noexcept
{
    return (data_);
}

/**
 * It sets the exit_ variable to the value passed in
 *
 * @param value The value to set the exit_ variable to.
 */
void ACore::setExit(bool value) noexcept
{
    exit_ = value;
}