/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include "Motocicleta.hpp"

Motocicleta::Motocicleta()
{
    tipo = "Moto";
}

std::ostream & Motocicleta::print(std::ostream & os) const
{
    os << "Moto:" << tipo << std::endl;
    
    return os;
}

std::ostream & operator<<(std::ostream & os, const Motocicleta & coche)
{
    return coche.print(os);
}