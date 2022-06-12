/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07pm-arthur.decaen
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) { _serial = serial; }

KoalaBot::KoalaBot() {}

KoalaBot::~KoalaBot() {}

void KoalaBot::setParts(const Arms &arms) { _arms = arms; }

void KoalaBot::setParts(const Legs &legs) { _legs = legs; }

void KoalaBot::setParts(const Head &head) { _head = head; }

void KoalaBot::swapParts(Arms &arms)
{
    Arms temp = _arms;
    _arms = arms;
    arms = temp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs temp = _legs;
    _legs = legs;
    legs = temp;
}

void KoalaBot::swapParts(Head &head)
{
    Head temp = _head;
    _head = head;
    head = temp;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional())
        return true;
    return false;
}