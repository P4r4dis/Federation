#include "../includes/Admiral.hpp"
#include <iostream>

Federation::Starfleet::Admiral::Admiral(std::string name) : 
_name(name), movePtr(&Federation::Starfleet::Ship::move)
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
