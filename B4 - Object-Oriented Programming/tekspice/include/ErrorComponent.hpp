/*
** EPITECH PROJECT, 2022
** ErrorComponent
** File description:
** ErrorComponent
*/

#include <iostream>

#ifndef ERRORCOMPONENT_HPP_
#define ERRORCOMPONENT_HPP_

class ErrorComponent : public std::exception {
private:
    std::string _msg = "Component, doesn't exist: ";

public:
    ErrorComponent(std::string component) { _msg += component; }
    ~ErrorComponent(){}

    const char *what() const noexcept override { return _msg.data(); }
};

#endif /* !ERRORCOMPONENT_HPP_ */