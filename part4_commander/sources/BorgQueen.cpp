#include "../includes/BorgQueen.hpp"

Borg::BorgQueen::BorgQueen() :  movePtr(&Borg::Ship::move)
{}

Borg::BorgQueen::~BorgQueen()
{}

bool        Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
        return (ship->*movePtr)(dest);
}