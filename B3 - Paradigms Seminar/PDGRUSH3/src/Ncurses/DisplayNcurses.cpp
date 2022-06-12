/*
** EPITECH PROJECT, 2022
** MyGkrellm.cpp
** File description:
** MyGkrellm
*/

#include "DisplayNcurses.hpp"

DisplayNcurses::DisplayNcurses(int ac, char **av) : IMonitorDisplay(ac, av)
{
    _user = new ModuleUser(0, 0, 50, 5);
    _computer = new ModuleComputer(0, 6, 50, 5);
    _time = new ModuleTime(122, 7, 50, 4);
    _cpu = new ModuleCpu(51, 0, 70, 8);
    _ram = new ModuleRam(122, 0, 50, 6);
    _network = new ModuleNetwork(51, 9, 70, 4);

    initscr();
    checkArgv(ac, av);
    noecho();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
}

DisplayNcurses::~DisplayNcurses()
{
    endwin();
}

bool DisplayNcurses::setDisp(char *str)
{
    IMonitorModule *mod[6] = {_user, _computer, _time, _cpu, _ram, _network};
    const char *flags[6] = {"-u", "-c", "-t", "-p", "-r", "-n"};
    bool display = false;

    for (int inc = 0; inc < 6; inc++)
        if (!strcmp(str, flags[inc])) {
            mod[inc]->show();
            display = true;
        }
    return display;
}

void DisplayNcurses::setOpt(char *str)
{
    if (!strcmp(str, "--color") || !strcmp(str, "--rainbow")) { start_color(); }
    if (!strcmp(str, "--rainbow")) { setRainbow(); }
}

void DisplayNcurses::showAll()
{
    IMonitorModule *mod[6] = {_user, _computer, _time, _cpu, _ram, _network};
    for (int i = 0; i < 6; i++)
        mod[i]->show();
}

void DisplayNcurses::checkArgv(int ac, char **argv)
{
    bool display = false;

    if (ac > 1)
        for (int i = 1; i != ac; i++) {
            setOpt(argv[i]);
            if (setDisp(argv[i]) && !display) {display = true;}
        }
    if (!display) { showAll(); }
}

bool DisplayNcurses::getUserEntry()
{
    timeout(99);
    int entry = getch();
    if (entry == 't') {_time->_isDisplay ? _time->hide() : _time->show();}
    if (entry == 'u') {_user->_isDisplay ? _user->hide() : _user->show();}
    if (entry == 'c') {_computer->_isDisplay ? _computer->hide() : _computer->show();}
    if (entry == 'r') {_ram->_isDisplay ? _ram->hide() : _ram->show();}
    if (entry == 'p') {_cpu->_isDisplay ? _cpu->hide() : _cpu->show();}
    if (entry == 'n') {_network->_isDisplay ? _network->hide() : _network->show();}
    if (entry == 'q') {return false;}
    return true;
}

void DisplayNcurses::refreshData()
{
    _user->refresh();
    _computer->refresh();
    _time->refresh();
    _cpu->refresh();
    _ram->refresh();
    _network->refresh();
}

bool DisplayNcurses::nextTurn()
{
    if (!getUserEntry())
        return false;

    refreshData();
    refresh();
    usleep(99999);
    return true;
}

bool DisplayNcurses::display() 
{
    clear();
    if (COLS < MAX_COLS || LINES < MAX_LINES) {
        printw("Too Small.");
        return nextTurn();
    }
    if (_rainbow) { showAll(); }
    _user->display();
    _computer->display();
    _time->display();
    _cpu->display();
    _ram->display();
    _network->display();
    return nextTurn();
}