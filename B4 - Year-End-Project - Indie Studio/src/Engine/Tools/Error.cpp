/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#include "Error.hpp"

/**
 * It moves the message into the message_ variable.
 *
 * @param message The message to be displayed when the error is thrown.
 */
Error::Error(const std::string_view& message) noexcept
    : message_(std::move(message.data())){};

/**
 * It returns a pointer to a C-style string that contains the error message
 *
 * @return A pointer to the string object's internal character array, which is not
 * null-terminated.
 */
const char* Error::what() const noexcept
{
    return (message_.c_str());
}