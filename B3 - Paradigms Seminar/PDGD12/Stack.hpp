/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** Stack
*/

#include <iostream>
#include <stack>

#ifndef STACK_HPP_
#define STACK_HPP_

class Stack : public std::stack<double>
{
public:
    class Error : public std::exception
    {
    private:
        std::string _msg;

    public:
        Error(std::string message) noexcept : _msg(message){};
        ~Error(){};

        const char *what() const noexcept override { return _msg.data(); }
        std::string getMsg() const { return _msg; }
    };
    Stack(){};
    ~Stack(){};

    double top() const;
    double pop();
    void push(double value) { c.push_front(value); };
    void add();
    void sub();
    void mul();
    void div();
};

#endif /* !STACK_HPP_ */
