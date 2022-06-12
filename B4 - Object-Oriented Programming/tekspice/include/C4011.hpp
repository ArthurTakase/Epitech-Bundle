/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** C4011
*/

#include "ErrorPin.hpp"
// #include "IComponent.hpp"
// #include "Gates.hpp"
#include "AComponent.hpp"

#ifndef C4011_HPP_
#define C4011_HPP_

class C4011 : virtual public AComponent {
private:
    std::array<nts::IComponent *, 14> pins;

public:
    C4011();
    ~C4011();
    void          simulate(std::size_t tick);
    void          setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    nts::Tristate compute(std::size_t pin);
    void          dump() const noexcept;
    nts::Type     typeComponent() const noexcept;
};

#endif /* !C4011_HPP_ */
