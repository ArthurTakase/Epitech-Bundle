/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Module
*/

#include <iostream>
#include <tuple>
#include <cstring>
#include <ncurses.h>

#ifndef MODULE_HPP_
#define MODULE_HPP_

class IMonitorModule
{
    private:
        int spaceSize(const char *str) { return (_width / 2) - (strlen(str) / 2); }

    public:
        bool        _isDisplay = false;
        int         _x = 0;
        int         _y = 0;
        int         _width = 0;
        int         _limit = 0;
        int         _line = 1;
        int         _color = (random() % 7) + 1;
        std::string _name = "";

    public:
        IMonitorModule(int x, int y, int width, int limit)
        {
            _x = x;
            _y = y;
            _width = width;
            _limit = limit;
        }

        void printStr(const char *str)
        {
            if (_line >= _limit) { _line = 1; }
            mvhline(_y + _line, _x, ACS_VLINE, 1);
            mvprintw(_y + _line, _x + spaceSize(str), str);
            mvhline(_y + _line, _x + _width, ACS_VLINE, 1);
            _line++;
        }

        void printTitle(const char *str)
        {
            attron(COLOR_PAIR(_color));
            mvhline(_y, _x, ACS_ULCORNER, 1);
            mvhline(_y, _x + _width, ACS_URCORNER, 1);
            mvhline(_y, _x + 1, ACS_HLINE, _width/2 - strlen(str)/2);
            mvprintw(_y, _x + (_width / 2) - (strlen(str) / 2), str);
            mvhline(_y, _x + _width/2 + (strlen(str)/2), ACS_HLINE, _width/2 - (strlen(str)/2));
        }

        void printBottom()
        {
            mvhline(_y + _limit, _x + 1, ACS_HLINE, _width);
            mvhline(_y + _limit, _x, ACS_LLCORNER, 1);
            mvhline(_y + _limit, _x + _width, ACS_LRCORNER, 1);
        }

        void show()
        {
            _isDisplay = true;
            _color = random() % 6 + 1;
        }

        ~IMonitorModule() {}
        void                hide() { _isDisplay = false; }
        void                display() {}
        void                refresh() {}
        virtual std::string getContent() = 0;
};

#endif /* !MODULE_HPP_ */
