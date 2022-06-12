/*
** EPITECH PROJECT, 2022
** B-PDG-300-BDX-3-1-PDGD07am-arthur.decaen
** File description:
** Federation
*/

#include "Borg.hpp"
#include "Federation.hpp"

// ---------------- STARFLEET SHIP ----------------

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWrap, int torpedo)
{
    _length = length;
    _maxWarp = maxWrap;
    _name = name;
    _width = width;
    _shield = 100;
    _photonTorpedo = torpedo;

    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (_photonTorpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWrap)
{
    _length = length;
    _maxWarp = maxWrap;
    _name = name;
    _width = width;
    _shield = 100;
    _photonTorpedo = 0;

    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::Ship()
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship() {}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;

    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    std::cout << "USS " << _name << ": The core is ";
    std::cout << (_core->checkReactor()->isStable() ? "stable" : "unstable");
    std::cout << " at the time." << std::endl;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _location != _home && _core->checkReactor()->isStable())
    {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable())
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move()
{
    if (_location != _home && _core->checkReactor()->isStable())
    {
        _location = _home;
        return true;
    }
    return false;
}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo <= torpedoes)
    {
        std::cout << _name << ": No enough torpedoes to fire , " << _captain->getName() << "!" << std::endl;
        return;
    }
    _photonTorpedo -= torpedoes;
    std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining ." << std::endl;
    target->setShield(target->getShield() - (50 * torpedoes));
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    Federation::Starfleet::Ship::fire(1, target);
}

// ---------------- NORMAL SHIP ----------------

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _maxWarp = 1;
    _name = name;
    _width = width;

    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship() {}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;

    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    std::cout << _name << ": The core is ";
    std::cout << (_core->checkReactor()->isStable() ? "stable" : "unstable");
    std::cout << " at the time." << std::endl;
}

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable())
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _location != _home && _core->checkReactor()->isStable())
    {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->checkReactor()->isStable())
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    if (_location != _home && _core->checkReactor()->isStable())
    {
        _location = _home;
        return true;
    }
    return false;
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return _core;
}

// ------------- STARFLEET CAPTAIN -------------

Federation::Starfleet::Captain::Captain(std::string name)
{
    _name = name;
}

Federation::Starfleet::Captain::~Captain() {}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

// ------------- STARFLEET ENSIGN -------------

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    _name = name;

    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign() {}