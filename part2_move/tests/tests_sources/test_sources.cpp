#include "../tests_includes/test_move.hpp"
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

Borg::Ship::Ship() : _side(300), _maxWarp(9)
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

////////////////////////////////////////////////////////////////
//CAPTAIN
///////////////////////////////////////////////////////////////
Federation::Starfleet::Captain::Captain(std::string name) : _name(name)
{}

Federation::Starfleet::Captain::~Captain()
{}

std::string Federation::Starfleet::Captain::getName(void)
{
    return _name;
}

int         Federation::Starfleet::Captain::getAge(void)
{
    return _age;
}

void        Federation::Starfleet::Captain::setAge(int  age)
{
    _age = age;
}

void        Federation::Starfleet::Ship::promote(Captain    *captain)
{
    std::cout   << captain->getName() 
                << ": I’m glad to be the captain of the USS "
                << this->_name << "." << std::endl;
}

//////////////////////////////////////////////////////////////////////
Federation::Starfleet::Ensign::Ensign(std::string     name) : _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{}