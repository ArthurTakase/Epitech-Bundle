/*
** EPITECH PROJECT, 2022
** MyGkrellm.hpp
** File description:
** MyGkrellm
*/

#include "../IMonitorDisplay.hpp"

#define MAX_COLS 155
#define MAX_LINES 14

#ifndef DISPLAYNCURSE_HPP_
#define DISPLAYNCURSE_HPP_

class DisplayNcurses : public IMonitorDisplay {
    public:
        DisplayNcurses(int ac, char **av);
        ~DisplayNcurses();

        bool    setDisp(char *str);
        bool    getUserEntry();
        bool    display();
        bool    nextTurn();
        void    checkArgv(int ac, char **argv);
        void    setOpt(char *str);
        void    refreshData();
        void    showAll();
};

#endif /* !DISPLAYNCURSE_HPP_ */
