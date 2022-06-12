#pragma once

#include "BaseComponent.hpp"

class Oxygenator : public BaseComponent
{
public:
    Oxygenator();
    virtual ~Oxygenator() {}

    void generateOxygen();
    void useOxygen(int quantity);

private:
    int _quantity;
};
