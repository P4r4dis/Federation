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

void            Federation::Starfleet::Ship::setupCore(WarpSystem::Core* core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void            Federation::Starfleet::Ship::checkCore()
{   
    std::string     stability = "";
    _core->checkReactor()->isStable() == true ? stability = "stable" : stability = "unstable";
    
    std::cout << "USS " << _name << ": The core is " << stability << " at the time." << std::endl;
}
///////////////////////////////////////////////////////
WarpSystem::QuantumReactor::QuantumReactor() : _stability(true)
{}

WarpSystem::QuantumReactor::~QuantumReactor()
{}

bool WarpSystem::QuantumReactor::getStability()
{
    return _stability;
}

bool WarpSystem::QuantumReactor::isStable()
{
    return getStability();
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}
///////////////////////////////////////////////////////////////
WarpSystem::Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor)
{}

WarpSystem::Core::~Core()
{}

WarpSystem::QuantumReactor  *WarpSystem::Core::checkReactor()
{
    return _coreReactor;
}

///////////////////////////////
Federation::Ship::Ship(int length, int width, std::string name) :
                                _length(length), _width(width), _name(name)
{
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and "
    << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{}

void                        Federation::Ship::setupCore(WarpSystem::Core* core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void            Federation::Ship::checkCore()
{   
    std::string     stability = "";
    _core->checkReactor()->isStable() == true ? stability = "stable" : stability = "unstable";
    
    std::cout << _name << ": The core is " << stability << " at the time." << std::endl;
}