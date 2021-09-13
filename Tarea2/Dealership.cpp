/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include "Dealership.hpp"
#include "Automovil.hpp"


std::string Dealership::getName()
{
    return name;
}

void Dealership::setName(std::string _name)
{
    name = _name;
}

std::string Dealership::getLastName()
{
    return lastName;
}

void Dealership::setLastName(std::string _lastName)
{
    lastName = _lastName;
}

std::string Dealership::getIne()
{
    return ine;
}

void Dealership::setIne(std::string _ine)
{
    ine = _ine;
}