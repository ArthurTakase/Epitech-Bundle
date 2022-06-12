/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** Output
*/

#include "AComponent.hpp"
#include "ErrorPin.hpp"

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

class Output : virtual public AComponent {
private:
    std::array<nts::IComponent *, 1> pins;
    size_t                           _otherPin;

public:
    Output();
    ~Output();
    void          simulate(std::size_t tick);
    void          setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    nts::Tristate compute(std::size_t pin);
    void          dump() const noexcept;
    nts::Type     typeComponent() const noexcept;

    class ErrorLink : public std::exception {
    private:
        std::string _msg = "Output not linked";

    public:
        ErrorLink() noexcept {};
        ~ErrorLink() {}

        const char *what() const noexcept override { return _msg.data(); }
    };
};

#endif /* !OUTPUT_HPP_ */