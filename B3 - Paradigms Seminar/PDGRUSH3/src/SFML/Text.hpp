/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Text
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef TEXT_HPP_
#define TEXT_HPP_

class Text {
    public:
        sf::Text _content;

    public:
        Text(sf::Font *font, int x, int y, int size, std::string str, sf::Color color)
        {
            _content.setFont(*font);
            _content.setString(str);
            _content.setCharacterSize(size);
            _content.setPosition(x, y);
            _content.setFillColor(color);
        }

        ~Text() {}
};

#endif /* !TEXT_HPP_ */
