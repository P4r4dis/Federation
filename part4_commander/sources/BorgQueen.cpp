#include "../includes/BorgQueen.hpp"

Borg::BorgQueen::BorgQueen() :  
movePtr(&Borg::Ship::move),
firePtr(&Borg::Ship::fire)
{}

Borg::BorgQueen::~BorgQueen()
{}

bool        Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
        return (ship->*movePtr)(dest);
}

void        Borg::BorgQueen::fire(Borg::Ship *ship,
            Federation::Starfleet::Ship *target)
{
    (ship->*firePtr)(target);
}