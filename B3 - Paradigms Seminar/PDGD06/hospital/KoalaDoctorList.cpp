/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaDoctorList
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doctor)
{
    this->content = doctor;
    this->next = NULL;
}

KoalaDoctorList::~KoalaDoctorList() {}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    return this->next;
}

void KoalaDoctorList::setNext(KoalaDoctorList *next)
{
    this->next = next;
}

void KoalaDoctorList::append(KoalaDoctorList *list)
{
    if (this->isEnd())
        this->setNext(list);
    else
        this->next->append(list);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *list)
{
    if (!list)
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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    KoalaDoctorList *current = this;
    KoalaDoctorList *before = NULL;

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
    return this;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    KoalaDoctorList *current = this;

    while(current != NULL)
        if (current->content && current->content->getName() == name)
                return current->getContent();
    return this->getContent();
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return this->content;
}

bool KoalaDoctorList::isEnd()
{
    if (this->getNext() == NULL)
        return true;
    return false;
}

void KoalaDoctorList::dump()
{
    std::cout << "Doctors: ";
    for (KoalaDoctorList *temp = this; temp; temp = temp->getNext()) {
        std::cout << (temp == this ? "" : ", ");
        std::cout << (temp->getContent() ? temp->getContent()->getName() : "[nullptr]");
    }
    std::cout << "." << std::endl;
}