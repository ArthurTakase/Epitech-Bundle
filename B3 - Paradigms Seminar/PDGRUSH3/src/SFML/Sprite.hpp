/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Sprite
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

class Sprite {
    public:
        sf::Sprite      _sprite;
        sf::Texture     _texture;

    public:
        Sprite(std::string file, int x, int y)
        {
            _texture.loadFromFile(file);
            _sprite.setTexture(_texture);
            _sprite.setPosition(x, y);
        }

        Sprite(std::string file, int x, int y, sf::IntRect rect)
        {
            _texture.loadFromFile(file, rect);
            _sprite.setTexture(_texture);
            _sprite.setPosition(x, y);
        }
        
        ~Sprite() {};
};

#endif /* !SPRITE_HPP_ */
