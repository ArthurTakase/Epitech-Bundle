/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** DisplaySFML
*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../IMonitorDisplay.hpp"
#include "Sprite.hpp"
#include "Text.hpp"
#include "Window.hpp"

#ifndef DISPLAYSFML_HPP_
#define DISPLAYSFML_HPP_

class DisplaySFML : public IMonitorDisplay {
    protected:
        sf::RenderWindow    *_window;
        sf::Font            _font;
        sf::Rect<float>     _all;

        Sprite              *s_background;
        Sprite              *s_mouse;
        Sprite              *s_cpu;
        Sprite              *s_ram;
        Sprite              *s_network;
        Sprite              *s_time;
        Sprite              *s_computer;
        Sprite              *s_user;
        Sprite              *s_rainbow;

        Window              *w_cpu;
        Window              *w_ram;
        Window              *w_network;
        Window              *w_time;
        Window              *w_computer;
        Window              *w_user;

    public:
        DisplaySFML(int ac, char **av);
        ~DisplaySFML();

        bool display();
        void newSprite(sf::Sprite *sprite, sf::Texture *texture, std::string file);
        void updateCursor();
        void checkColision();
        void switchText();
        void drawAll();
        void getEvent();
        void refreshData();
};

#endif /* !DISPLAYSFML_HPP_ */
