
#include "Automovil.hpp"
#include <iostream>

Automovil::Automovil()
{
    tipo = "Auto";
}

std::ostream & Automovil::print(std::ostream & os) const
{
    os << "Auto: " << code << std::endl;
    return os;
}

std::ostream & operator << (std::ostream & os, const Automovil & coche)
{
    return coche.print(os);
}
