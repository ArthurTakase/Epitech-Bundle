/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *koala)
{
    this->content = koala;
    this->next = NULL;
}

SickKoalaList::~SickKoalaList() {}

bool SickKoalaList::isEnd()
{
    if (this->getNext() == NULL)
        return true;
    return false;
}

void SickKoalaList::append(SickKoalaList *next)
{
    if (this->isEnd())
        this->setNext(next);
    else
        this->next->append(next);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *list)
{
    if (list == NULL)
        return this;
    if (list == this)
        return this->next;
    if (this->next) {
        if (this->next == list)
            this->next = this->next->getNext();
        else
            this->next->remove(list);
    }
    return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    SickKoalaList *current = this;
    SickKoalaList *before = NULL;

    while(current != NULL) {
        if (current->content && current->content->getName() == name) {
            if (before) {
                before->setNext(current->getNext());
                current->setNext(NULL);
                break;
            } else {
                before = current->getNext();
                current->setNext(NULL);
            }
            before = current;
            current = current->next;
        }
    }
    return(this);
}

SickKoala *SickKoalaList::getContent()
{
    return this->content;
}

SickKoalaList *SickKoalaList::getNext()
{
    return this->next;
}

void SickKoalaList::setNext(SickKoalaList *list)
{
    this->next = list;
}

void SickKoalaList::dump()
{
    std::cout << "Patients: ";
    for (SickKoalaList *temp = this; temp; temp = temp->getNext()) {
        std::cout << (temp == this ? "" : ", ");
        std::cout << (temp->getContent() ? temp->getContent()->getName() : "[nullptr]");
    }
    std::cout << "." << std::endl;
}
