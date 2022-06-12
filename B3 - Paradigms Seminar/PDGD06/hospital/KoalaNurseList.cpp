/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaNurseList
*/

#include "KoalaNurseList.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *koala)
{
    this->content = koala;
    this->next = NULL;
}

KoalaNurseList::~KoalaNurseList() {}

bool KoalaNurseList::isEnd()
{
    if (this->getNext() == NULL)
        return true;
    return false;
}

KoalaNurseList *KoalaNurseList::getNext()
{
    return this->next;
}

KoalaNurse *KoalaNurseList::getContent()
{
    return this->content;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    KoalaNurseList *current = this;

    while(current != NULL)
        if (current->content && current->content->getID() == id)
            return current->getContent();
    return(NULL);
}

void KoalaNurseList::setNext(KoalaNurseList *list)
{
    this->next = list;
}

void KoalaNurseList::append(KoalaNurseList *list)
{
    if (this->isEnd())
        this->setNext(list);
    else
        this->next->append(list);
}

void KoalaNurseList::dump()
{
    std::cout << "Nurses: ";
    for (KoalaNurseList *temp = this; temp; temp = temp->getNext()) {
        std::cout << (temp == this ? "" : ", ");
        std::cout << (temp->getContent() ? std::to_string(temp->getContent()->getID()) : "[nullptr]");
    }
    std::cout << "." << std::endl;
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *list)
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

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    KoalaNurseList *current = this;
    KoalaNurseList *before = NULL;

    while(current != NULL) {
        if (current->content && current->content->getID() == id) {
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