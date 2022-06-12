/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** C4030
*/

#include "AComponent.hpp"
#include "ErrorPin.hpp"

#ifndef C4030_HPP_
#define C4030_HPP_

class C4030 : virtual public AComponent {
private:
    std::array<nts::IComponent *, 14> pins;

public:
    C4030();
    ~C4030();
    void          simulate(std::size_t tick);
    void          setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
    nts::Tristate compute(std::size_t pin);
    void          dump() const noexcept;
    nts::Type     typeComponent() const noexcept;
};

#endif /* !C4030_HPP_ */
