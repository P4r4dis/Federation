#include "../includes/Admiral.hpp"
#include <iostream>

Federation::Starfleet::Admiral::Admiral(std::string name) : _name(name)
{
    std::cout << "Admiral " << _name << " ready for action." << std::endl;
}

Federation::Starfleet::Admiral::~Admiral()
{}

std::string     Federation::Starfleet::Admiral::getName(void)
{
    return _name;
}