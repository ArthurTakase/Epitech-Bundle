/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07pm-arthur.decaen
** File description:
** KoalaBot
*/

#include "Parts.hpp"

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

class KoalaBot
{
    Arms _arms;
    Legs _legs;
    Head _head;
    std::string _serial = "Bob-01";

public:
    KoalaBot();
    KoalaBot(std::string);
    ~KoalaBot();
    void setParts(const Arms &);
    void setParts(const Legs &);
    void setParts(const Head &);
    void swapParts(Arms &);
    void swapParts(Legs &);
    void swapParts(Head &);
    void informations() const;
    bool status() const;
};

#endif /* !KOALABOT_HPP_ */
