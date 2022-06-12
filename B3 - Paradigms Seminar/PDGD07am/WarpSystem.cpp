/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07am-arthur.decaen
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor() {}

WarpSystem::QuantumReactor::~QuantumReactor() {}

bool WarpSystem::QuantumReactor::isStable()
{
    return _stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}

WarpSystem::Core::Core(WarpSystem::QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

WarpSystem::Core::~Core() {}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return _coreReactor;
}