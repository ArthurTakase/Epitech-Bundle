/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id)
{
    this->id = id;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *koala)
{
    koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string report)
{
    std::string drug = "";
    std::string toErase = ".report";
    size_t pos = std::string::npos;
    char c;

    std::ifstream file (report.c_str());
    if (file.is_open()) {
        c = file.get();
        for (; file.good(); c = file.get())
            drug.push_back(c);
    } else
        return "";
    while ((pos  = report.find(toErase) )!= std::string::npos)
        report.erase(pos, toErase.length());
    std::cout << "Nurse " << this->id << ": Kreog! Mr." << report << " needs a " << drug << "!" << std::endl;
    return drug;
}

void KoalaNurse::timeCheck()
{
    static bool time = true;

    if (time)
        std::cout << "Nurse " << this->id << ": Time to get to work!" << std::endl;
    else
        std::cout << "Nurse " << this->id << ": Time to go home to my eucalyptus forest!" << std::endl;
    time = !time;
}

int KoalaNurse::getID()
{
    return this->id;
}