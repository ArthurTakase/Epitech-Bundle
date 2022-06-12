/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#include "../include/NanoTekSpice.hpp"

NanoTekSpice::NanoTekSpice()
{
    _tick = -1;
}

NanoTekSpice::~NanoTekSpice() {}

void NanoTekSpice::simulateAll() noexcept
{
    while (!_assignationToDo.empty()) {
        std::array<std::string, 2> arr = popAssignation();
        setValue(arr[0], arr[1]);
    }
    for (auto it = _components.begin(); it != _components.end(); ++it) { it->second->simulate(_tick); }
    _tick++;
}

void NanoTekSpice::dumpAll() noexcept
{
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        std::cout << it->first << "\t";
        it->second->dump();
    }
}

void NanoTekSpice::displayAll() noexcept
{
    std::vector<std::string> outputs_data;
    std::vector<std::string> outputs_name;

    std::cout << "tick: " << _tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if (it->second->typeComponent() == nts::Type::INPUT || it->second->typeComponent() == nts::Type::CLOCK)
            std::cout << "  " << it->first << ": " << it->second->printableType() << std::endl;
        else if (it->second->typeComponent() == nts::Type::OUTPUT) {
            outputs_name.push_back(it->first);
            outputs_data.push_back(it->second->printableType());
        }
    }

    std::cout << "output(s):" << std::endl;
    for (size_t i = 0; i != outputs_name.size(); i++) {
        std::cout << "  " << outputs_name[i] << ": " << outputs_data[i] << std::endl;
    }

    outputs_name.clear();
    outputs_data.clear();
}

void NanoTekSpice::loop() noexcept
{
    while (1) {
        simulateAll();
        displayAll();
        _tick++;
    }
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &NanoTekSpice::getComponents() noexcept
{
    return _components;
}

bool NanoTekSpice::invalidState(nts::Tristate state) const noexcept
{
    return (state != nts::Tristate::UNDEFINED && state != nts::Tristate::TRUE && state != nts::Tristate::FALSE);
}

void NanoTekSpice::setValue(std::string key, std::string state)
{
    std::map<std::string, nts::Tristate> values = { { "U", nts::Tristate::UNDEFINED },
                                                    { "1", nts::Tristate::TRUE },
                                                    { "0", nts::Tristate::FALSE } };

    if (!_components[key]) return;
    if (_components[key]->typeComponent() == nts::Type::INPUT || _components[key]->typeComponent() == nts::Type::CLOCK)
        _components[key]->setValue(values[state]);
}

void NanoTekSpice::pushAssignation(std::array<std::string, 2> arr)
{
    _assignationToDo.push(arr);
}

std::array<std::string, 2> NanoTekSpice::popAssignation()
{
    std::array<std::string, 2> arr = _assignationToDo.top();
    _assignationToDo.pop();
    return arr;
}
