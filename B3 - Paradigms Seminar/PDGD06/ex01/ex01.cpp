/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD06-arthur.decaen
** File description:
** ex00
*/

#include <iostream>

int main(void)
{
    float n;
    std::string type;

    std::cin >> n >> type;
    std::cout.precision(3);
    if (type == "Celsius") {
        std::cout.width(16);
        std::cout << std::fixed << std::right << (n * 9 / 5) + 32;
        std::cout.width(16);
        std::cout << std::right <<  "Fahrenheit" << std::endl;
    }
    else if (type == "Fahrenheit") {
        std::cout.width(16);
        std::cout << std::right << std::fixed << 5.0 / 9.0 * (n - 32);
        std::cout.width(16);
        std::cout << std::right << "Celsius" << std::endl;
    }
    return 0;
}