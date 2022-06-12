/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->name = name;
    std::cout << "Dr." << this->name <<": I'm Dr." << this->name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor() {}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string drugs[5] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};

    std::cout << "Dr." << this->name << ": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    patient->poke();
    std::ofstream MyFile(patient->getName() + ".report");
    MyFile << drugs[random() % 5];
    MyFile.close();
}

void KoalaDoctor::timeCheck()
{
    static bool time = true;

    if (time)
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
    else
        std::cout << "Dr." << this->name << ": Time to go home to my eucalyptus forest!" << std::endl;
    time = !time;
}

std::string KoalaDoctor::getName()
{
    return this->name;
}
