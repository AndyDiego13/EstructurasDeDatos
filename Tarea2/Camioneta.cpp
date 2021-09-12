/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include "Camioneta.hpp"
#include <iostream>

Camioneta::Camioneta()
{
    tipo = "Camioneta";
    traction = "4WD";
}

std::ostream & Camioneta::print(std::ostream & os) const
{
    os << "Camioneta: " << tipo << "- Traccion: " << traction << std::endl;
    return os;
}

std::ostream & operator << (std::ostream & os, const Camioneta & coche)
{
    return coche.print(os);
}
