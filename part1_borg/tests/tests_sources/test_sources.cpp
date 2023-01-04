#include "../tests_includes/test_Borg.hpp"
#include <iostream>

void    redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
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

