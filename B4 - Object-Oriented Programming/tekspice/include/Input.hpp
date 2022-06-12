/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** Input
*/

#include "AComponent.hpp"
#include "ErrorPin.hpp"
#include "IComponent.hpp"

#ifndef INPUT_HPP_
#define INPUT_HPP_

class Input : virtual public AComponent {
private:
    std::array<nts::IComponent *, 1> pins;
    nts::Type                        _type;

public:
    Input();
    Input(nts::Type);
    ~Input();
    void          simulate(std::size_t tick);
    void          setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    nts::Tristate compute(std::size_t pin);
    void          dump() const noexcept;
    nts::Type     typeComponent() const noexcept;
};

#endif /* !INPUT_HPP_ */
