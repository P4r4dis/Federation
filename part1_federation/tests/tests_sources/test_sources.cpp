#include "../tests_includes/test_my_federation.hpp"
#include <iostream>

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name,
                                short maxWarp) :
                                _length(length), _width(width), _name(name),
                                _maxWarp(maxWarp)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and "
    << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{}

WarpSystem::QuantumReactor::QuantumReactor() : _stability(true)
{}

WarpSystem::QuantumReactor::~QuantumReactor()
{}

bool WarpSystem::QuantumReactor::getStability()
{
    return _stability;
}