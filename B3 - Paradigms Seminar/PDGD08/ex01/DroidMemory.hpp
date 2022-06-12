/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD08-arthur.decaen
** File description:
** DroidMemory
*/

#include <iostream>

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

class DroidMemory
{
    size_t _fingerprint = random();
    size_t _exp = 0;

public:
    DroidMemory();
    ~DroidMemory();
    void setFingerprint(size_t);
    void setExp(size_t);
    size_t getFingerprint() const;
    size_t getExp() const;
    DroidMemory &operator<<(DroidMemory &);
    DroidMemory &operator>>(DroidMemory &);
    DroidMemory &operator+=(DroidMemory const &);
    DroidMemory &operator+=(size_t);
    DroidMemory &operator+(size_t &);
};

std::ostream &operator<<(std::ostream &, DroidMemory const &);

#endif /* !DROIDMEMORY_HPP_ */
