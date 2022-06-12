/*
** EPITECH PROJECT, 2022
** Window
** File description:
** Window
*/

#include "../IMonitorModule.hpp"
#include "Sprite.hpp"
#include "Text.hpp"

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

class Window
{
    public:
        bool            _isDisplay = false;
        Text            *t_content;

    private:
        int             _x;
        int             _y;
        Sprite          *_sprite;
        IMonitorModule  *_mod;
        Text            *t_title;
        
    public:
        Window(IMonitorModule *mod, int x, int y, sf::Font *font, sf::IntRect rect)
        {
            _mod = mod;
            _x = x;
            _y = y;
            _sprite = new Sprite("assets/img/window.png", _x, _y, rect);
            t_title = new Text(font, x + 10, y + 1, 17, mod->_name, sf::Color::White);
            t_content = new Text(font, x + 10, y + 50, 18, mod->getContent(), sf::Color::Black);
        }
        
        ~Window()
        {
            delete _sprite;
            delete t_title;
            delete t_content;
        }
        
        void refresh()
        {
            t_content->_content.setString(_mod->getContent());
        }

        void display(sf::RenderWindow *_window)
        {
            if (!_isDisplay) return;
            _window->draw(_sprite->_sprite);
            _window->draw(t_title->_content);
            _window->draw(t_content->_content);
        }

        void setDisplay() { _isDisplay = !_isDisplay; }

};

#endif /* !WINDOW_HPP_ */