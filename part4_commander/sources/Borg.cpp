#include "../includes/Borg.hpp"
#include <iostream>

Borg::Ship::Ship(int weaponFrequency, short repair) :   _side(300), _maxWarp(9),
                                                        _location(_home),
                                                        _shield(100),
                                                        _weaponFrequency(weaponFrequency),
                                                        _repair(repair)
{
    std::cout << "We are the Borgs." << 
    " Lower your shields and surrender yourselves unconditionally."
    << std::endl;
    std::cout << "Your biological" << 
    " characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{}

void                Borg::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
}

WarpSystem::Core    *Borg::Ship::getCore(void)
{
    return _core;
}

void                Borg::Ship::checkCore(void)
{    
    _core->checkReactor()->isStable() == true ?
    std::cout << "Everything is in order." << std::endl :
    std::cout << "Critical failure imminent." << std::endl;
}

Destination         Borg::Ship::getLocation(void)
{
    return _location;
}

Destination         Borg::Ship::getHome(void)
{
    return _home;
}

bool                Borg::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->getStability() == true)
    {
        _location = d;
        return true;
    }
    else
        return false;
}

bool                Borg::Ship::move(int warp)
{
    return move(warp, _home);
    // if (warp <= getMaxWarp() && _home != _location && _core->checkReactor()->getStability() == true)
    // {
    //     _location = _home;
    //     return true;
    // }
    // else
    //     return false;
}

bool                Borg::Ship::move(Destination d)
{
    return move(_maxWarp, d);
    // if (d != _location && _core->checkReactor()->getStability() == true)
    // {
    //     _location = d;
    //     return true;
    // }
    // else
    //     return false;
}

bool                Borg::Ship::move(void)
{
    return move(_maxWarp, _home);
    // if (_core->checkReactor()->getStability() == true)
    // {
    //     _location = _home;
    //     return true;
    // }
    // else
    //     return false;
}

int                 Borg::Ship::getShield(void)
{
    return _shield;
}

void                Borg::Ship::setShield(int shield)
{
    _shield = shield;
}

int                 Borg::Ship::getWeaponFrequency(void)
{
    return _weaponFrequency;
}

void                Borg::Ship::setWeaponFrequency(int weaponFrenquency)
{
    _weaponFrequency = weaponFrenquency;
}

short               Borg::Ship::getRepair(void)
{
    return _repair;
}

void                Borg::Ship::setRepair(short repair)
{
    _repair = repair;
}

void                Borg::Ship::repair(void)
{
    if(_repair > 0)
    {
        _repair--;
        _shield = 100;
        std::cout   << "Begin shield re-initialisation... "
                    << "Done. Awaiting further instructions." << std::endl;
    }
    else
        std::cout   << "Energy cells depleted, shield weakening." << std::endl;
}

void                Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
        std::cout   << "Firing on target with " << _weaponFrequency 
                    << " GW frequency." << std::endl; 
        target->setShield(target->getShield() - (_weaponFrequency));
        if(target->getShield() < 0)
            target->setShield(0);
}

void                Borg::Ship::fire(Federation::Ship *target)
{
        std::cout   << "Firing on target with " << _weaponFrequency 
                    << " GW frequency." << std::endl; 
        target->getCore()->checkReactor()->setStability(false);
}