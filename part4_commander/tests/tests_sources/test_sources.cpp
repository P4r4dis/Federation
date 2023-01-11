#include "../tests_includes/test_commander.hpp"
#include <iostream>

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Federation::Starfleet::Ship::Ship(int length, int width, std::string name,
                                short maxWarp, int torpedo = 0) :
                                _length(length), _width(width), _name(name),
                                _maxWarp(maxWarp), _location(_home),
                                _shield(100), _torpedo(torpedo)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and "
    << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (torpedo > 0)
        std::cout << "Weapons are set: " << _torpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::Ship() :   _length(289), _width(132), 
                                        _name("Entreprise"), _maxWarp(6), 
                                        _location(_home), _shield(100),
                                        _torpedo(0)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and "
    << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;}

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

Destination     Federation::Starfleet::Ship::getLocation(void)
{
    return _location;
}

Destination     Federation::Starfleet::Ship::getHome(void)
{
    return _home;
}

bool            Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->checkReactor()->getStability() == true)
    {
        _location = d;
        return true;
    }
    else
        return false;
}

bool            Federation::Starfleet::Ship::move(int warp)
{
    return move(warp, _home);
    // if (warp <= _maxWarp && _home != _location && _core->checkReactor()->getStability() == true)
    // {
    //     _location = _home;
    //     return true;
    // }
    // else
    //     return false;
}

bool            Federation::Starfleet::Ship::move(Destination d)
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

bool            Federation::Starfleet::Ship::move(void)
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

int             Federation::Starfleet::Ship::getShield(void)
{
    return _shield;
}

void            Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int             Federation::Starfleet::Ship::getTorpedo(void)
{
    return _torpedo;
}

void            Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _torpedo = torpedo;
}

void            Federation::Starfleet::Ship::fire(int torpedeos, Borg::Ship *target)
{
    if (torpedeos <= _torpedo) 
    {
        _torpedo = _torpedo - torpedeos;
        std::cout   << _name << ": Firing on target. " << _torpedo 
                    << " torpedoes remaining." << std::endl;
        target->setShield(target->getShield() - (50 * torpedeos));
        if(target->getShield() < 0)
            target->setShield(0);
    }
    else if (_torpedo)
    {
        std::cout   << _name << ": No more torpedo to fire, "
                    << _captain->getName() << "!" << std::endl;
    }
    else
    {
        std::cout   << _name << ": No enough torpedoes to fire, "
                    << _captain->getName() << "!" << std::endl;
    }

}

void            Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    return fire(1, target);
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
                                _length(length), _width(width), _name(name),
                                _location(_home)
{
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and "
    << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{}

void            Federation::Ship::setupCore(WarpSystem::Core* core)
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

Destination     Federation::Ship::getLocation(void)
{
    return _location;
}

Destination     Federation::Ship::getHome(void)
{
    return _home;
}

int             Federation::Ship::getMaxWarp(void)
{
    return 1;
}

bool            Federation::Ship::move(int warp, Destination d)
{
    if (warp <= getMaxWarp() && d != _location && _core->checkReactor()->getStability() == true)
    {
        _location = d;
        return true;
    }
    else
        return false;
}

bool            Federation::Ship::move(int warp)
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

bool            Federation::Ship::move(Destination d)
{
    return move(getMaxWarp(), d);
    // if (d != _location && _core->checkReactor()->getStability() == true)
    // {
    //     _location = d;
    //     return true;
    // }
    // else
    //     return false;
}

bool            Federation::Ship::move(void)
{
    return move(getMaxWarp(), _home);
    // if (_core->checkReactor()->getStability() == true)
    // {
    //     _location = _home;
    //     return true;
    // }
    // else
    //     return false;
}

WarpSystem::Core    *Federation::Ship::getCore(void)
{
    return _core;
}

///////////////////////////////////////////////////////////
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
        // setShield(target->getShield() - (50 * _weaponFrequency));
        // if(target->getShield() < 0)
        //     target->setShield(0);
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
    _captain = captain;
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

///////////////////////////////////////////////////////////////////////////
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