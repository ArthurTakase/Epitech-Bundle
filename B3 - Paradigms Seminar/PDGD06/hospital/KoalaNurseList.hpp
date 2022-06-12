/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaNurseList
*/

#ifndef KOALANURSELIST_HPP_
#define KOALANURSELIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList {
    KoalaNurse *content;
    KoalaNurseList *next;
    public:
        KoalaNurseList(KoalaNurse*);
        ~KoalaNurseList();
        KoalaNurseList *getNext();
        void setNext(KoalaNurseList *);
        void append(KoalaNurseList *);
        KoalaNurseList *remove(KoalaNurseList*);
        KoalaNurseList *removeFromID(int);
        KoalaNurse *getFromID(int id);
        KoalaNurse *getContent();
        bool isEnd();
        void dump();
};

#endif /* !KOALANURSELIST_HPP_ */
