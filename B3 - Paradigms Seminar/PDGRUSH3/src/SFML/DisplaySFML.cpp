/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** DisplaySFML
*/

#include "DisplaySFML.hpp"

DisplaySFML::DisplaySFML(int argc, char **argv) : IMonitorDisplay(argc, argv)
{
    _user = new ModuleUser(0, 0, 50, 5);
    _computer = new ModuleComputer(0, 6, 50, 5);
    _time = new ModuleTime(122, 7, 50, 4);
    _cpu = new ModuleCpu(51, 0, 70, 8);
    _ram = new ModuleRam(122, 0, 50, 6);
    _network = new ModuleNetwork(51, 9, 70, 4);

    _all = sf::FloatRect(0, 590, 68, 10);
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Kreog!");
    _font.loadFromFile("assets/font/Windows_Regular.ttf");

    s_background = new Sprite("assets/img/rush98.png", 0, 0);
    s_mouse = new Sprite("assets/img/cursor.png", 0, 0);
    s_time = new Sprite("assets/img/time.png", 20, 20);
    s_computer = new Sprite("assets/img/pc.png", 20, 100);
    s_cpu = new Sprite("assets/img/cpu.png", 20, 180);
    s_ram = new Sprite("assets/img/ram.png", 20, 260);
    s_network = new Sprite("assets/img/world.png", 20, 340);
    s_user = new Sprite("assets/img/users.png", 20, 420);
    s_rainbow = new Sprite("assets/img/rainbow.png", 778, 582);

    w_time = new Window(_time, 110, 30, &_font, sf::IntRect(0, 0, 447, 100));
    w_computer = new Window(_computer, 320, 60, &_font, sf::IntRect(0, 0, 447, 130));
    w_cpu = new Window(_cpu, 90, 170, &_font, sf::IntRect(0, 0, 447, 210));
    w_ram = new Window(_ram, 335, 280, &_font, sf::IntRect(0, 0, 447, 160));
    w_network = new Window(_network, 120, 410, &_font, sf::IntRect(0, 0, 447, 100));
    w_user = new Window(_user, 310, 430, &_font, sf::IntRect(0, 0, 447, 130));

    s_cpu->_sprite.setScale(1.25, 1.25);
    s_ram->_sprite.setScale(1.25, 1.25);
    s_mouse->_sprite.setScale(0.10, 0.10);
    s_rainbow->_sprite.setScale(0.4, 0.4);
    _window->setMouseCursorVisible(false);
    _window->setFramerateLimit(30);
}

DisplaySFML::~DisplaySFML()
{
    delete _window;
    delete s_background;
    delete s_mouse;
    delete s_time;
    delete s_computer;
    delete s_cpu;
    delete s_ram;
    delete s_network;
    delete s_user;
    delete s_rainbow;
    delete w_time;
    delete w_computer;
    delete w_cpu;
    delete w_ram;
    delete w_network;
    delete w_user;
}

void DisplaySFML::updateCursor()
{
    sf::Vector2i pos = sf::Mouse::getPosition();
    s_mouse->_sprite.setPosition(pos.x - 5, pos.y - 80);
    _window->draw(s_mouse->_sprite);
}

void DisplaySFML::drawAll()
{
    _window->draw(s_background->_sprite);
    _window->draw(s_cpu->_sprite);
    _window->draw(s_ram->_sprite);
    _window->draw(s_network->_sprite);
    _window->draw(s_time->_sprite);
    _window->draw(s_computer->_sprite);
    _window->draw(s_user->_sprite);
    _window->draw(s_rainbow->_sprite);
    w_time->display(_window);
    w_computer->display(_window);
    w_cpu->display(_window);
    w_ram->display(_window);
    w_network->display(_window);
    w_user->display(_window);
    updateCursor();
}

void DisplaySFML::checkColision()
{
    static bool isDisplay = true;
    Sprite* sprites[6] = { s_time, s_computer, s_cpu, s_ram, s_network, s_user };
    Window *win[6] = { w_time, w_computer, w_cpu, w_ram, w_network, w_user };
    
    for (int i = 0; i < 6; i++) {
        if (s_mouse->_sprite.getGlobalBounds().intersects(sprites[i]->_sprite.getGlobalBounds())) {
            win[i]->setDisplay();
            return;
        }
    }
    if (s_mouse->_sprite.getGlobalBounds().intersects(_all)) {
        for (int i = 0; i < 6; i++)
            win[i]->_isDisplay = isDisplay;
        isDisplay = !isDisplay;
        return;
    }
    if (s_mouse->_sprite.getGlobalBounds().intersects(s_rainbow->_sprite.getGlobalBounds()))
        setRainbow();

    return;
}

void DisplaySFML::getEvent()
{
    sf::Event event;
    while (_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {_window->close();}
        if (event.type == sf::Event::MouseButtonPressed) {checkColision();}
    }
}

void DisplaySFML::refreshData()
{
    Window *win[6] = { w_time, w_computer, w_cpu, w_ram, w_network, w_user };
    sf::Color colors[8] = { sf::Color::Black, sf::Color::Red, sf::Color::White,
                            sf::Color::Green, sf::Color::Blue, sf::Color::Yellow,
                            sf::Color::Magenta, sf::Color::Cyan };
    
    for (int i = 0; i < 6; i++) {
        win[i]->refresh();
        win[i]->t_content->_content.setFillColor( _rainbow ? colors[random() % 8] : sf::Color::Black);
    }

}

bool DisplaySFML::display()
{
    IMonitorModule *mod[6] = { _time, _computer, _cpu, _ram, _network, _user };

    while (_window->isOpen()) {
        _window->clear(sf::Color::Red);
        getEvent();
        refreshData();
        drawAll();
        _window->display();
    }
    return true;
}