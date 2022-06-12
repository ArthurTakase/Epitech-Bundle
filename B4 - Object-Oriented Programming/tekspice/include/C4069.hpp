/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** C4069
*/

#include "AComponent.hpp"
#include "ErrorPin.hpp"

#ifndef C4069_HPP_
#define C4069_HPP_

class C4069 : virtual public AComponent {
private:
    std::array<nts::IComponent *, 14> pins;

public:
    C4069();
    ~C4069();
    void          simulate(std::size_t tick);
    void          setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    nts::Tristate compute(std::size_t pin);
    void          dump() const noexcept;
    nts::Type     typeComponent() const noexcept;
};

#endif /* !C4069_HPP_ */
