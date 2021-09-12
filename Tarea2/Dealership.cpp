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

std::string Dealership::getName()
{
    return name;
}

std::string Dealership::getLastName()
{
    return lastName;
}

std::string Dealership::getIne()
{
    return ine;
}

int Dealership::getEarnings()
{
    return earnings;
}

void Dealership::menu()
{
    //Se muestran las opciones
    std::cout << "-----DEALERSHIP-----" << std::endl;
    std::cout << "Opcion menu:" << std::endl;
    std::cout << "1. Sign up" << std::endl;
    std::cout << "2. Select what type of car are you looking for" << std::endl;
    
}