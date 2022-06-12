/*
** EPITECH PROJECT, 2022
** B-OOP-400-BDX-4-1-tekspice-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** IComponent
*/

#include <iostream>
#include <memory>

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace nts {
enum class Tristate { UNDEFINED = -1, TRUE = 1, FALSE = 0 };
enum Type { INPUT, OUTPUT, COMPONENT, CLOCK, TRUE, FALSE };
class IComponent {
public:
    virtual ~IComponent()                                                                        = default;
    virtual void          simulate(std::size_t tick)                                             = 0;
    virtual void          setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    virtual nts::Tristate compute(std::size_t pin)                                               = 0;
    virtual nts::Tristate getValue() const noexcept                                              = 0;
    virtual void          setValue(nts::Tristate new_value) noexcept                             = 0;
    virtual void          dump() const noexcept                                                  = 0;
    virtual nts::Type     typeComponent() const noexcept                                         = 0;
    virtual std::string   printableType() const noexcept                                         = 0;
};
} // namespace nts

#endif /* !ICOMPONENT_HPP_ */
