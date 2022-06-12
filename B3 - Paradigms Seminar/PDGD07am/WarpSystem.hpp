/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07am-arthur.decaen
** File description:
** WarpSystem
*/

#include <string>
#include <iostream>

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor
    {
    private:
        bool _stability = true;

    public:
        QuantumReactor();
        ~QuantumReactor();
        bool isStable();
        void setStability(bool);
    };

    class Core
    {
    private:
        QuantumReactor *_coreReactor;

    public:
        Core(QuantumReactor *);
        ~Core();
        QuantumReactor *checkReactor();
    };
}

#endif
