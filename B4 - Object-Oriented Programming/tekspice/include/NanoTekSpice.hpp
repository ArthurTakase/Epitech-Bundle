/*
** EPITECH PROJECT, 2022
** NanoTekSpice
** File description:
** NanoTekSpice
*/

#include "ManagerComponent.hpp"
#include <map>
#include <stack>
#include <vector>

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

class NanoTekSpice {
private:
    std::map<std::string, std::unique_ptr<nts::IComponent>> _components;
    size_t                                                  _tick;
    std::stack<std::array<std::string, 2>>                  _assignationToDo;

public:
    NanoTekSpice();
    ~NanoTekSpice();

    void                                                     simulateAll() noexcept;
    void                                                     dumpAll() noexcept;
    void                                                     displayAll() noexcept;
    void                                                     loop() noexcept;
    void                                                     setValue(std::string, std::string);
    void                                                     pushAssignation(std::array<std::string, 2> arr);
    bool                                                     invalidState(nts::Tristate state) const noexcept;
    std::map<std::string, std::unique_ptr<nts::IComponent>> &getComponents() noexcept;
    std::array<std::string, 2>                               popAssignation();

public:
    class ErrorSetValue : public std::exception {
    private:
        std::string _msg;

    public:
        ErrorSetValue(std::string err_msg) noexcept : _msg(err_msg){};
        ~ErrorSetValue() {}

        const char *what() const noexcept override { return _msg.data(); }
    };
};

void splitStr(std::string str, std::string delimiter, std::vector<std::string> *result);

#endif /* !NANOTEKSPICE_HPP_ */
