/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL: Ubuntu-20.04]
** File description:
** AComponent
*/

#include "Gates.hpp"

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

class AComponent : virtual public nts::IComponent {
protected:
    nts::Tristate _value;
    bool          _isSwitchThisTurn;
    nts::Tristate (*method)(nts::Tristate var1, nts::Tristate var2);

public:
    AComponent(nts::Tristate (*)(nts::Tristate var1, nts::Tristate var2));
    ~AComponent();
    bool          pinExist(std::size_t pin, size_t nb_pin_max) const noexcept;
    nts::Tristate getValue() const noexcept;
    std::string   printableType() const noexcept;
    void          setValue(nts::Tristate new_value) noexcept;

public:
    virtual void          simulate(std::size_t tick)                                             = 0;
    virtual void          setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    virtual nts::Tristate compute(std::size_t pin)                                               = 0;
    virtual void          dump() const noexcept                                                  = 0;
    virtual nts::Type     typeComponent() const noexcept                                         = 0;
};

#endif /* !ACOMPONENT_HPP_ */
