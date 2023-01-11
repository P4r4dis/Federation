#include "../includes/Admiral.hpp"
#include <iostream>

Federation::Starfleet::Admiral::Admiral(std::string name) : 
_name(name), movePtr(&Federation::Starfleet::Ship::move),
firePtr(&Federation::Starfleet::Ship::fire)
{
    std::cout << "Admiral " << _name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{}

std::string     Federation::Starfleet::Admiral::getName(void)
{
    return _name;
}

bool            Federation::Starfleet::Admiral::move(Federation::Starfleet::Ship *ship, Destination dest)
{
    return (ship->*movePtr)(dest);
}

void            Federation::Starfleet::Admiral::fire(
                Federation::Starfleet::Ship *ship, Borg::Ship *target)
{
    std::cout << "On order from Admiral " << _name << ":" << std::endl;
    (ship->*firePtr)(target);
}