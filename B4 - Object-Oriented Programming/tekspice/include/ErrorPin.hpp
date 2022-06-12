/*
** EPITECH PROJECT, 2022
** ErrorPin
** File description:
** ErrorPin
*/

#include <iostream>

#ifndef ERRORPIN_HPP_
#define ERRORPIN_HPP_

class ErrorPin : public std::exception {
private:
    std::string _msg = "Pin, doesn't exist: ";

public:
    ErrorPin(size_t nb_pin) noexcept { _msg += std::to_string(nb_pin); }
    ~ErrorPin() {}

    const char *what() const noexcept override { return _msg.data(); }
};

#endif /* !ERRORPIN_HPP_ */
