/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD10pm-arthur.decaen
** File description:
** Errors
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
    _message = message;
    _component = component;
}

char const *NasaError::what() const noexcept
{
    return _message.c_str();
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component)
    : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component)
    : NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component)
    : NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message)
    : NasaError(message, "CommunicationDevice")
{
}