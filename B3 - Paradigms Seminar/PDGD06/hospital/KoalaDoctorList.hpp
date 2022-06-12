/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaDoctorList
*/

#ifndef KOALADOCTORLIST_HPP_
#define KOALADOCTORLIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList {
    std::string name;
    KoalaDoctor *content;
    KoalaDoctorList *next;
    public:
        KoalaDoctorList(KoalaDoctor*);
        ~KoalaDoctorList();
        KoalaDoctorList *getNext();
        void setNext(KoalaDoctorList *);
        void append(KoalaDoctorList *);
        KoalaDoctorList *remove(KoalaDoctorList*);
        KoalaDoctorList *removeFromName(std::string name);
        KoalaDoctor *getFromName(std::string name);
        KoalaDoctor *getContent();
        bool isEnd();
        void dump();
};

#endif /* !KOALADOCTORLIST_HPP_ */
