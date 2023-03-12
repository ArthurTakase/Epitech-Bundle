/*
** EPITECH PROJECT, 2022
** YEP
** File description:
** IsInstanceOf.cpp
*/

#pragma once

namespace Tools
{

/**
 * @brief Used to compare the type of two objects
 *
 * @tparam Base target type
 * @param ptr object to compare
 * @return true if the object is of the same type as the target type, false otherwise
 */
template <typename Base, typename T>
inline bool instanceOf(const T* ptr)
{
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

}