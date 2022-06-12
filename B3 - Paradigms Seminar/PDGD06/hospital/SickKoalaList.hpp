/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** SickKoalaList
*/

#ifndef SICKKOALALIST_HPP_
#define SICKKOALALIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList {
    SickKoala *content;
    SickKoalaList *next;

    public:
        SickKoalaList(SickKoala *);
        ~SickKoalaList();
        bool isEnd();
        void append(SickKoalaList *);
        SickKoalaList *remove(SickKoalaList *);
        SickKoalaList *removeFromName(std::string);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void setNext(SickKoalaList *);
        void dump();
};

#endif /* !SICKKOALALIST_HPP_ */
