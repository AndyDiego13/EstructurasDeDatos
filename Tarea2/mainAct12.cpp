/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include <vector>
#include <initializer_list>
#include "Motocicleta.hpp"
#include "Camioneta.hpp"

int main(int argc, char const *argv[])
{
    std::vector<Auto *> autos;

    auto a1 = new Auto(); //Auto * a1 = new Auto;
    auto m1 = new Motocicleta();
    auto c1 = new Camioneta();
    auto a2 = new Auto();

    autos.push_back(a1);
    autos.push_back(m1);
    autos.push_back(c1);
    autos.push_back(a2);

    for (auto a : autos)
    {
        std::cout << *a << std::endl;
        delete a;
    }
    
    return 0;
}