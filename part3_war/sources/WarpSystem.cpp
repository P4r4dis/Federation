#include "../includes/WarpSystem.hpp"

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
//////////////////////////////////////////////////////////////////////
WarpSystem::Core::Core(QuantumReactor *coreReactor) : _coreReactor(coreReactor)
{}

WarpSystem::Core::~Core()
{}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return _coreReactor;
}