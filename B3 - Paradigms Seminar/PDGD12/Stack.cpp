/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD12-arthur.decaen [WSL: Ubuntu-20.04]
** File description:
** Stack
*/

#include "Stack.hpp"

double Stack::top() const
{
    if (this->empty())
        throw Error("Empty Stack");
    return c.front();
}

double Stack::pop()
{
    double result;

    try
    {
        result = this->top();
    }
    catch (const std::exception &e)
    {
        throw e;
    }
    c.pop_front();
    return result;
}

void Stack::add()
{
    if (this->size() < 2)
        throw Error("Not enought operands");
    double v1 = this->pop();
    double v2 = this->pop();
    c.push_front(v1 + v2);
}

void Stack::sub()
{
    if (this->size() < 2)
        throw Error("Not enought operands");
    double v1 = this->pop();
    double v2 = this->pop();
    c.push_front(v1 - v2);
}

void Stack::mul()
{
    if (this->size() < 2)
        throw Error("Not enought operands");
    double v1 = this->pop();
    double v2 = this->pop();
    c.push_front(v1 * v2);
}

void Stack::div()
{
    if (this->size() < 2)
        throw Error("Not enought operands");
    double v1 = this->pop();
    double v2 = this->pop();
    c.push_front(v1 / v2);
}