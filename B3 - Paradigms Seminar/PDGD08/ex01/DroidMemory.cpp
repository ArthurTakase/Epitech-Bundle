/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD08-arthur.decaen
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() {}

DroidMemory::~DroidMemory() {}

void DroidMemory::setFingerprint(size_t fingerprint) { _fingerprint = fingerprint; }

void DroidMemory::setExp(size_t exp) { _exp = exp; }

size_t DroidMemory::getFingerprint() const { return _fingerprint; }

size_t DroidMemory::getExp() const { return _exp; }

DroidMemory &DroidMemory::operator<<(DroidMemory &other)
{
    this->_exp += other._exp;
    this->_fingerprint = this->_fingerprint ^ other._fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &other)
{
    other._exp += this->_exp;
    this->_fingerprint = other._fingerprint ^ this->_fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory const &other)
{
    this->_exp += this->_exp;
    this->_fingerprint = this->_fingerprint ^ this->_fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t exp)
{
    this->_exp = this->_exp + exp;
    this->_fingerprint = this->_fingerprint ^ exp;
    return *this;
}

DroidMemory &DroidMemory::operator+(size_t &exp)
{
    DroidMemory *result = new DroidMemory();

    result->_exp = this->_exp + exp;
    result->_fingerprint = this->_fingerprint ^ exp;
    return *result;
}

std::ostream &operator<<(std::ostream &os, DroidMemory const &k)
{
    os << "DroidMemory '" << k.getFingerprint() << "', " << k.getExp();
    return os;
}