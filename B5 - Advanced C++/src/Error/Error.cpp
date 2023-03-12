/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-arcade-solene.lefeu
** File description:
** Error
*/

#include <Error/Error.hpp>

/**
 * Construct an Error object with a message.
 *
 * @param message The error message to be displayed.
 */
Error::Error(std::string message) noexcept
    : message_(std::move(message)){};

/**
 * It returns a pointer to a C-style string that contains the error message
 *
 * @return A pointer to the string object's internal character array.
 */
const char* Error::what() const noexcept
{
    return (message_.c_str());
}

/**
 * `InitError` is a constructor that takes a `std::string` and calls the `Error` constructor with that
 * string
 *
 * @param message The message to be displayed when the error is thrown.
 */
InitError::InitError(std::string message) noexcept
    : Error(std::move(message)){};

/**
 * It's a constructor for the NetworkError class that takes a string as an argument and passes it
 * to the Error class constructor
 *
 * @param message The message to be displayed when the error is thrown.
 */
NetworkError::NetworkError(std::string message) noexcept
    : Error(std::move(message)){};
